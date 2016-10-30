#### perform execution via cpp | dot

#ifndef INITSTYLE

#define WITH_ROLE
#define WITH_REQ


#### general macros
#########################################

#define _QUOTEME(x) #x
#define QUOTEME(x) _QUOTEME(x)

#define startpoint(name) { rank=source name_begin [shape=point style=filled fillcolor=black label=""]}
#define endpoint(name)   { rank=sink name_end [shape=doublecircle style=filled fillcolor=black label=""]}

#define END }


#### general style
#########################################
#define INITSTYLE style=rounded; compound=True; fontname=Helvetica; \
    edge [style=bold fontname=Helvetica]; node [fontname=Helvetica];
// rounded style, helvetica as font, activate cluster connections


### Grouping
#########################################

#define tosource(nodes...) {rank=source nodes}
#define tosink(nodes...) {rank=sink nodes}
#define tostart(nodes...) {rank=min nodes}
#define toend(nodes...) {rank=max nodes}
#define group(nodes...) {rank=same nodes}
#define pair(x,y) subgraph x##y {rank=same; x y}


### Cluster handling
#########################################

#define fromcluster(clustername,name) name [ltail=cluster_##clustername]
#define tocluster(clustername,name) name [lhead=cluster_##clustername]
#define cluster(name,longname,additional...) subgraph cluster##_##name  { additional label=longname;
#define rolecluster(name,longname,additional...) cluster (name,longname, additional begin_##name;)
#define extcluster(name,longname,additional...) \
    cluster(name,longname, graph [color="grey" style=filled]  node [bgcolor="white"] additional)
#define putcluster(first,anchor) { rank=same; anchor first }
#define endcluster }

### actor handling
#########################################

#ifdef WITH_ROLE

#define showactor(name,longname...) { name [shape=plaintext color=ROLECOLOR label=<\
<TABLE BORDER="0" CELLBORDER="0" CELLSPACING="0" >\
<TR><TD><IMG SRC="actor3.png"/></TD></TR><TR ><TD rowspan="2"> longname </TD></TR></TABLE>>]}

#define showrole(who,nodename) showactor(nodename,who##BRName)
#define rolename(who) QUOTEME(who##Name)
#define role(who,what,additional...) { what [style=filled color=who##Color additional]}


#define appName         Presenter
#define appBRName       Presenter
#define appColor       "/set312/5"

#define secName         EC-Office
#define secBRName       EC-Office
#define secColor       "/set312/7"

#define meetsecName     EC-Meeting-Secretary
#define meetsecBRName   EC-Meeting<br/>Secretary
#define meetsecColor   "/set312/1"

#define revName         EC-Internal-Review
#define revBRName       EC-Internal<br/>Review
#define revColor       "/set312/8"

#define execName        EC-Executive-Board
#define execBRName      EC-Executive<br/>Board
#define execColor       "/set312/4"

#define signName        EC-Signing
#define signBRName      EC-Signing
#define signColor      "/set312/12"

#define statName        EC-Statistic
#define statBRName      EC-Statistic
#define statColor      "darkolivegreen4"

#define notrevName      EC-Notification-Review
#define notrevBRName    EC-Notification<br/>Review
#define notrevColor    "/set312/10"

#define insrevName      EC-Insurance-Review
#define insrevBRName    EC-Insurance<br/>Review
#define insrevColor    "grey78"

#define thesisrevName   EC-Thesis-Review
#define thesisrevBRName EC-Thesis<br/>Review
#define thesisrevColor  "khaki4"

#define thesisexecName  EC-Thesis-Executive
#define thesisexecBRName EC-Thesis<br/>Executive
#define thesisexecColor "khaki3"

#define boardName       Board-Member
#define boardBRName     Board<br/>Member
#define boardColor      "/set312/6"

#define extrevName      External-Reviewer
#define extrevBRName    External<br/>Reviewer
#define extrevColor     "peru"

#define unknownName     Unknown-Actor
#define unknownBRName   Unknown<br/>Actor
#define unknownColor   "/set312/9"

#define autoName        "Automatic--Transition"
#define autoBRName      System
#define autoColor      "/set312/9"

#else
#define role(who,what) { }
#define rolename(who) { }
#define showrole(name,description...} { style=invis ; name}
#endif


### Requirement handling
#########################################

#ifdef WITH_REQ
#define req(name,text...) { name [LINESTYLE, color=DEFINITIONCOLOR]; \
    name [shape=DEFINITIONSHAPE, color=DEFINITIONCOLOR] }
#else
#define req(name,text...) { style=invis; name}
#endif


### activity workflow handling
#########################################

### workflow settings
#define TASKCOLOR lightblue
#define AUTOTASKCOLOR lightgrey
#define EXTERNALTASKCOLOR maroon2
#define DOCUMENTCOLOR darkgoldenrod1

#define CASECOLOR yellow
#define SWITCHCOLOR deepskyblue
#define YESCOLOR green
#define NOCOLOR firebrick1


### workflow macros

#define WORKFLOW(longname)  digraph S { label=longname; INITSTYLE

#define case(short,longname...) { short [shape=diamond style=filled color="black" fillcolor=CASECOLOR \
label=<<TABLE BORDER="0" CELLBORDER="0" CELLSPACING="0" >\
<TR><TD> longname </TD></TR></TABLE>>] }

#define switch(from,to,labelname...) from -> to [label=QUOTEME(labelname) color=SWITCHCOLOR];

#define yesno(short,x,y,long...) case(short,long);\
    short -> x [label="yes" color=YESCOLOR]; \
    short -> y [label="no" color=NOCOLOR]

#define stateyesno(short,x,y,statex,statey,long...) case(short,long);\
    short -> x [label=QUOTEME(statex) color=YESCOLOR]; \
    short -> y [label=QUOTEME(statey) color=NOCOLOR]

#define yesnogroup(short,x,y,long...) pair(x,y) yesno(short,x,y,long)

#define distributor(name,additional...) { name [shape=hexagon style=filled color=autoColor label=QUOTEME(additional) ] }
#define collector(name,additional...) distributor(name,additional)
#define barrier(name,additional...) distributor(name,additional)

#define document(short,nr,longname...) { short [shape=invhouse style=filled fillcolor=DOCUMENTCOLOR \
label=<<TABLE BORDER="0" CELLBORDER="0" CELLSPACING="0" >\
<TR><TD> longname </TD></TR></TABLE>>] }

#define external(short,nr,longname...) { short [shape=ellipse style=filled fillcolor=EXTERNALTASKCOLOR \
label=<<TABLE BORDER="0" CELLBORDER="0" CELLSPACING="0" >\
<TR><TD> longname </TD></TR></TABLE>>] }

#define olddoit(tablestyle,short,nr,where,how,longname...) { short [shape=none label=<\
<TABLE BORDER="0" CELLBORDER="1" CELLSPACING="0" tablestyle>\
<TR><TD WIDTH="10"> nr </TD>\
    <TD ROWSPAN="2"> longname </TD>\
    <TD WIDTH="10"> where </TD></TR>\
<TR><TD WIDTH="10"> how </TD><TD> </TD></TR>\
</TABLE>>]}
//#define task(short,nr,longname...) doit(BGCOLOR=QUOTEME(TASKCOLOR),short,nr,EC,,longname)
//#define autotask(short,nr,longname...) doit(BGCOLOR=QUOTEME(AUTOTASKCOLOR),short,nr,EC,A,longname)

#define _DOIT(who,short,nr,how,longname...) { short [shape=none label=<\
<TABLE BORDER="0" CELLBORDER="1" CELLSPACING="0" BGCOLOR=who##Color>\
<TR><TD WIDTH="10" ALIGN="LEFT"> nr </TD>\
    <TD WIDTH="90" ROWSPAN="2" ALIGN="CENTER"> longname</TD>\
    <TD WIDTH="10" ROWSPAN="2" ALIGN="RIGHT"> who##BRName </TD></TR>\
<TR><TD WIDTH="10" ALIGN="LEFT"> how </TD></TR>\
</TABLE>>]}

#define task(who,short,nr,longname...) _DOIT(who,short,nr,,longname)
#define roletask(who,short,nr,longname...) _DOIT(who,short,nr,,longname)
#define autotask(short,nr,longname...) _DOIT(auto,short,nr,A,longname)


### activity workflow legend
#########################################

#define WORKFLOWLEGEND cluster(workflow_legend,"Activity Workflow Legend")\
    edge [style=invis]\
    ratio=fill\
\
    exampletask -> exampleautotask -> exampledocument -> examplebarrier -> examplequestion\
\
    {rank=same\
    task(sec,exampletask,1,Human Task) -> taskdescription;\
    taskdescription [shape=record, label="Top-Left: Use-case ID, Top-Right: Actor\n Center: Operation performed\nFillColor: Taken from Actor"]\
    }\
\
    {rank=same\
    autotask(exampleautotask,,Computer Task) -> autotaskdescription;\
    autotaskdescription [shape=record, label="Top-Left: Use-case ID (if applicable)\n Top-Right: System as Actor\n Bottom-Left: 'A' for automatic operation\n Center: Operation automatically performed"]\
    }\
\
    {rank=same\
    document(exampledocument,,Example Document) -> documentdescription;\
    documentdescription [shape=record, label="Paper or Screen Report"]\
    }\
\
    {rank=same\
    barrier(examplebarrier,Example Barrier) -> barrierdescription;\
    barrierdescription [shape=record, label="Collector for all incoming edges\nwaits until all of them arrived\nDistributor of all outgoing edges\nstarts all of them in parallel"]\
    }\
\
    {edge [style=solid] yesno(examplequestion,questionyes,questionno,Example Decision)}\
    {rank=same  edge [style=invis]  examplequestion -> questiondescription}\
    questiondescription [shape=record, label="Decision to make,\n yes=green, no=red"]\
}



### processflow handling
#########################################

### state colors
#define NORMALCOLOR black
#define CONDITIONALCOLOR darkviolet
#define INDIRECTCOLOR black
#define AUTOMATICCOLOR grey
#define PASSCOLOR "forestgreen:firebrick"
#define PASSSTYLE style=dashed, penwidth=2

#define PREREQUISITECOLOR "/paired12/12"
### brown
#define SETSTATECOLOR "/paired12/4"
### green
#define SETSTATERETURNCOLOR "/paired12/2"
### blueviolet
#define CREATEANDSETCOLOR "/paired12/8"
### yellow
#define ADDVALUECOLOR "/paired12/5"
### maroon2
#define CREATEANDADDVALUECOLOR "/paired12/6"
### red

### state
#define STATESHAPE ellipse
#define STATESTYLE solid

#define MACROSTATESHAPE shape=hexagon style=filled color=black fillcolor=orange
#define DATASETSHAPE shape=house style=filled color=black fillcolor=olivedrab4
#define OBJECTSHAPE shape=invtrapezium style=filled color=olivedrab3


#### role
#define ROLESHAPE trapezium
#define ROLECOLOR lightblue

#### definition
#define DEFINITIONSHAPE box
#define DEFINITIONCOLOR orange

#### arrows for states
#define CREATEARROW normalvee
#define VALUEARROW diamond
#define CREATEVALUEARROW diamondvee
#define PREREQUISITEARROW normalonormal

#define ARROWSIZE 2
#define LINEWIDTH 3
#define LINETYPE dashed
#define LINESTYLE style=LINETYPE, penwidth=LINEWIDTH, arrowsize=ARROWSIZE
### minlen=2


### processflow macros
#########################################

#define PROCESSFLOW(longname) digraph S { label=longname; INITSTYLE INITPROCESSFLOW

#define INITPROCESSFLOW node [ shape=STATESHAPE, style=STATESTYLE];
// Initial node styling


### State Handling

#define state(from,to,morestyle...)    from -> to \
    [style=STATESTYLE morestyle]
#define automatic(from,to,morestyle...) from -> to \
    [style=STATESTYLE penwidth=LINEWIDTH color=AUTOMATICCOLOR morestyle]
#define indirect(from,to,morestyle...) from -> to \
    [style=LINETYPE, color=INDIRECTCOLOR morestyle]
#define pass(from,to,morestyle...) from -> to \
    [PASSSTYLE, color=PASSCOLOR, dir=both, minlen=1,  morestyle]
#define conditional(from,to,morestyle...) from -> to \
    [LINESTYLE, color=CONDITIONALCOLOR morestyle]
#define setstate(from,to,morestyle...) from -> to \
    [LINESTYLE, color=SETSTATECOLOR morestyle]
#define return(from,to,morestyle...)   from -> to \
    [LINESTYLE, color=SETSTATERETURNCOLOR, arrowtail=dot morestyle]
#define prerequisite(from,to,morestyle...) from -> to \
    [LINESTYLE, color=PREREQUISITECOLOR arrowhead=PREREQUISITEARROW morestyle]
#define create(from,to,morestyle...) from -> to \
    [LINESTYLE, color=CREATEANDSETCOLOR, arrowhead=CREATEARROW morestyle]
#define addvalue(from,to, morestyle...) from -> to \
    [LINESTYLE, color=ADDVALUECOLOR, arrowhead=VALUEARROW morestyle]
#define createandvalue(from,to,morestyle...) from -> to \
    [LINESTYLE, color=CREATEANDADDVALUECOLOR, arrowhead=CREATEVALUEARROW morestyle]


#define macro(from,morestyle...) { from [MACROSTATESHAPE morestyle] }
#define dataset(from,morestyle...) { from [DATASETSHAPE morestyle] }
#define object(from,morestyle...) { from [OBJECTSHAPE morestyle] }
#define branch(name,additional...) { name [shape=diamond style=filled color=autoColor label=QUOTEME(additional) width=0.5] }


### processflow legend
#########################################

#define PROCESSFLOWLEGEND cluster(processflow_legend,"Processflow Legend")\
    graph [ranksep="1.5"] \
    { edge [style=invis]; a1 -> b1 -> c1 -> d1 -> e1 -> f1 -> g1 -> h1 -> i1\
     i1 -> s1 -> t1 -> u1 -> v1} \
    edge [minlen=7] \
    {rank=same a1 state(a1,a2,label="User activated State Transition\n")}\
    {rank=same b1 indirect(b1,b2, label="State Transition via Sub-Process\n")}\
    {rank=same c1 conditional(c1,c2, label="Automatic Transition\n if Condition is met")}\
    {rank=same d1 setstate(d1,d2, label="Intra Workflow Object\n Transition activation\n")}\
    {rank=same e1 return(e1,e2, label="Intra Workflow Object\n Transition activation\n and end of Sub-Workflow\n")}\
    {rank=same f1 create(f1,f2, label="Create Sub-Workflow Object\n and set Transition state\n")}\
    {rank=same g1 createandvalue(g1,g2,label="Create Sub-Workflow Object\n and add value to State\n")}\
    {rank=same h1 addvalue(h1,h2,label="Add Value to\n Sub-Workflow Object State\n")}\
    {rank=same i1 prerequisite(i1,i2,label="h1 is prerequisite State of\n Workflow Object State h2\n")}\
    edge [minlen=1]\
    extcluster(exampleexternal,"External Workflow Object")\
        role(app,exampleextstate, label="Object State")\
    }\
    {rank=same s1 state(s1,exampleextstate, label="External Workflow Reference") }  \
    {rank=same {t1 [shape=plaintext label="Call to External Macro Workflow"]} -> macro(examplemacro,label="Macro Workflow")}\
    {rank=same u1 automatic(role(auto,u1),u2,label="Automatic-Transition") branch(u2) automatic(u2,u3,label="Decision")}\
    {rank=same {v1 [shape=plaintext label="Data Storage Set"]} -> dataset(exampledata,label="Example Dataset")}\
}

#define ACTORLEGEND cluster(actor_legend,"Actor Color Legend")\
    graph [ranksep="1.5"] \
    edge [minlen=1]\
    { edge [style=invis]; \
          a1 -> a2 -> b1 -> b2   a1 -> c1 -> c2 -> d1 -> d2 \
    c1 -> e1 -> e2 -> f1 -> f2   e1 -> g1 -> g2 -> h1 -> h2 \
    g1 -> i1 -> i2 -> j1 -> j2   i1 -> k1 -> k2 -> l1 -> l2 \
    k1 -> m1 -> m2 -> n1 -> n2}\
    {rank=same showrole(app,a1)       -> role(app,a2, label="")        showrole(sec,b1)        -> role(sec,b2, label="") }\
    {rank=same showrole(meetsec,c1)   -> role(meetsec,c2, label="")    showrole(rev,d1)        -> role(rev,d2, label="") }\
    {rank=same showrole(exec,e1)      -> role(exec,e2, label="")       showrole(sign,f1)       -> role(sign,f2, label="") }\
    {rank=same showrole(stat,g1)      -> role(stat,g2, label="")       showrole(notrev,h1)     -> role(notrev,h2, label="") }\
    {rank=same showrole(insrev,i1)    -> role(insrev,i2, label="")     showrole(board,j1)      -> role(board,j2, label="") }\
    {rank=same showrole(thesisrev,k1) -> role(thesisrev,k2, label="")  showrole(thesisexec,l1) -> role(thesisexec,l2, label="") }\
    {rank=same showrole(extrev,m1)    -> role(extrev,m2, label="")     n1 [style=invis shape=none];  n2 [style=invis shape=none]; }\
}


#endif


### Products
#####################################

#define image(name,file,longname) { name [shape=plaintext label=<<TABLE BORDER="0" CELLBORDER="0" CELLSPACING="0">\
<TR><TD><IMG SRC=QUOTEME(file)/></TD></TR><TR><TD rowspan="2"> longname </TD></TR></TABLE>>]}
#define prod(which,longname,additional...) { which [label=longname shape=component style=filled color=lightblue additional]}

#define usedir(protocol,direction) [dir=direction label=QUOTEME(protocol) color=QUOTEME(protocol##color) penwidth=2]
#define bidir(protocol) usedir(protocol,both)
#define unidir(protocol) usedir(protocol,forward)
#define presentdir(protocol) {protocol [style=filled fillcolor=QUOTEME(protocol##color)]}
#define httpcolor darkgreen
#define httpscolor green
#define sqlcolor brown
#define rediscolor darkorange
#define smtpcolor blue
#define filecolor pink
#define memcachecolor gold

#define PROTOCOLLEGEND cluster(protocol_legend,"Protocol Color Legend") \
    graph[ranksep="1.5"] \
    edge [minlen=1 style=invis] \
    presentdir(http) -> presentdir(https) -> presentdir(sql) ->  presentdir(redis) -> presentdir(smtp) -> presentdir(file) -> presentdir(memcache) \
    }
