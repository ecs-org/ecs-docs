# ECS-Documentation

This is the documentation repository of the ethics committee system.

See [the ECS-Hompage](https://ecs-org.github.io/ecs-docs) for Information about ECS.

+ Documentation is written using [Sphinx](http://sphinx-doc.org/)
    + Sourcefiles can be restructured text and markdown
        + markdown support is using [recommonmark](https://github.com/rtfd/recommonmark/)
    + HTML and PDF documentation is generated as output
        + latex is used to generate pdfs
    + Available graph support
        + plantuml, graphviz with cpp support, actdiag, nwdiag, seqdiag, blockdiag
    + Additional available sphinx extensions
        + sphinxcontrib-programoutput sphinxcontrib.youtube sphinxcontrib-inlinesyntaxhighlight
+ The Homepage is rendered using [Pelican](https://blog.getpelican.com/)
    + Sourcefiles can be restructured text and markdown
        + markdown support is using [python markdown](https://pythonhosted.org/Markdown/)
    + HTML is generated as output
  
## Quickstart

### install

#### clone ecs-docs source
if you are ok with `~/ecs-docs`:

```
cd ~/
git clone https://github.com/ecs-org/ecs-docs ecs-docs
```

somewhere else:

```
git clone https://github.com/ecs-org/ecs-docs targetdirectoryyouwant/ecs-docs
ln -sft ~/ targetdirectoryyouwant/ecs-docs
```

#### setup
```
ln -sft ~/bin ~/ecs-docs/scripts/*
sudo scripts/os-deps-ecs-docs.sh
scripts/user-deps-ecs-docs.sh
```

### build
```
build-all-ecs-docs.sh
firefox _build/index.html
evince _build/ecs*.pdf
```

### build single item
```
# activate environment
. _env/bin/activate
cd user-manual-de
make clean html latexpdf
firefox _build/html/index.html
```

loop: `make html; firefox _build/html/index.html`

### build and update static target repository
```
force-push-build.sh
```
