# Digital signed pdf documents

The ECS uses Mocca and PDF-AS to create digital signed pdf documents.

Mocca and PDF-AS are developed by EGIZ, the eGovernment Innovation Centre of Austria a joint initiative of the Federal Chancellery and the Graz University of Technology, at the Institute for Applied Information Processing and Communications Technology (IAIK).

* [EGIZ Mocca - a modular, open source citizen card environment](http://www.egiz.gv.at/en/schwerpunkte/9-MOCCA)
* [EGIZ PDF-AS - a java framework for creating digitial signatures on PDF documents](http://www.egiz.gv.at/en/schwerpunkte/16-pdf-as)

## Mocca

Info:
  * Current Mocca: 1.3.27 (2017-06-29), also available: 1.3.28 (2017-07-26), but missing "war"
  * [Mocca Description](https://joinup.ec.europa.eu/software/mocca/description)
  * [Mocca Homepage](https://joinup.ec.europa.eu/site/mocca/index.html)
  * [bkucommon Configuration](https://joinup.ec.europa.eu/site/mocca/bkucommon/configuration.html)
  * [BKUOnline](https://joinup.ec.europa.eu/site/mocca/BKUOnline/)
  * [BKUOnline Deployment](https://joinup.ec.europa.eu/site/mocca/BKUOnline/deployment.html)
  * [BKUOnline Configuration](https://joinup.ec.europa.eu/site/mocca/BKUOnline/configuration.html)
  * [BKUOnline Upgrade Info](https://joinup.ec.europa.eu/site/mocca/BKUOnline/upgrade13.html)
  * [Security Analysis of the Austrian Citizen Card Environment MOCCA and E-Card](https://www.auto.tuwien.ac.at/bib/pdf_TR/TR0174.pdf)

Download:
  * [Download Site](https://joinup.ec.europa.eu/site/mocca)
  * [bkuonline-1.3.27.war](https://joinup.ec.europa.eu/system/files/project/bkuonline-1.3.27.war)

```
sha256=f43f49cbd7ef4df56741097ff5f0637a83cf6cb64701bc484633257ec122dc6a  bkuonline-1.3.23.war
sha256=c3a7270294bc3a43790061e9eec059ef6a124eb3bd55d20edfd8a7b6b6b89b23  bkuonline-1.3.27.war
```
  * Optional: [bkuwebstart-1.3.27_0.zip](https://joinup.ec.europa.eu/system/files/project/bkuwebstart-1.3.27_0.zip)

Sourcecode:
  * [http://git.egiz.gv.at/mocca](http://git.egiz.gv.at/mocca)

### Changes

* MOCCA 1.3.28 (unused)
  * Library Update
  * Information: Missing ".war" in released files
* MOCCA 1.3.27
  * Security Bugfix
* MOCCA 1.3.26
  * New card implementation (A-Trust signature card CardOSV5.3)
* MOCCA 1.3.25
  * MOCCA Library Update
  * Bugfix
* MOCCA 1.3.24
  * Fixed problem, which occured when using MOCCA together with MOA-ID in a single webapp container.
  * System-Properties include now the prefix ".jnlp"
* MOCCA 1.3.23
  * First ECS Version

## PDF-AS

Info:
  * Current PDF-AS:4.1.0 (2017-01-17), previous: 4.0.11 (2016-07-01)
  * [PDF-AS Description](https://joinup.ec.europa.eu/software/pdf-as/description)
  * [Documenation - DE](https://joinup.ec.europa.eu/site/pdf-as/releases/4.0.11/docs/PDFAS4_Dokumentation.pdf)
  * [Web Interface Documenation - DE](https://joinup.ec.europa.eu/site/pdf-as/releases/4.0.11/docs/PDFAS4_WebDokumentation.pdf)
  * [External Service Documentation - DE](https://joinup.ec.europa.eu/site/pdf-as/releases/4.0.11/docs/AnbindungExterneWebanwendung.pdf)
  * [Profile Documentation -  DE](https://joinup.ec.europa.eu/site/pdf-as/releases/4.0.11/docs/PDFAS4_Profile_Dokumentation.pdf)
  * [Goverment Profile Documentation - DE](https://www.ref.gv.at/uploads/media/Layout_Amtssignatur_las_2-0-1_20140610.pdf)
  * [PDF-AS Workshop Part 1 - DE](http://demo.egiz.gv.at/padesWorkshop/20141209%20Signatur-Workshop-PDF-AS-4.0-Hands-On%20Teil1.pdf)
  * [PDF-AS Workshop Part 2 - DE](http://demo.egiz.gv.at/padesWorkshop/20141209%20Signatur-Workshop-PDF-AS-4.0-Hands-On%20Teil2.pdf)
  * [Goverment sponsored Digital Signature Test Site - DE](https://www.buergerkarte.at/einfach-signieren/)

Download:
  * [Download Site](https://joinup.ec.europa.eu/site/pdf-as/releases/4.1.0/)
  * [pdf-as-web-4.1.0.war](https://joinup.ec.europa.eu/site/pdf-as/releases/4.1.0/pdf-as-web-4.1.0.war)
```
sha256=2008e413032fc926e30b2d666f4363707328a5171a4b170c0fb0599a4e894421  pdf-as-web-4.0.11.war
sha256=d625cd40a0baadf9ccf2a9bb46f6808efb7929e3fbe107b087b8c42f5b6c1971  pdf-as-web-4.1.0.war
```
  * [defaultConfig.zip](https://joinup.ec.europa.eu/site/pdf-as/releases/4.1.0/cfg/defaultConfig.zip) 
```
sha256=ea28689b77094eb03017acdfb11ed1a571ec4bdb27905a2f06205eddbe931fcc defaultConfig.zip
```
  * Optional:
    * [pdf-as-web.properties](https://joinup.ec.europa.eu/site/pdf-as/releases/4.1.0/cfg/pdf-as-web.properties)
    

Sourcecode:
  * [http://git.egiz.gv.at/pdf-as-4/](http://git.egiz.gv.at/pdf-as-4/)
  * [automated builds from source](https://joinup.ec.europa.eu/site/pdf-as/maven/at/gv/egiz/pdfas/)

### Changes

* PDF-AS 4.1

  * PDF-AS Library
    * a new pdf backend is available based on pdfbox 2.0.3, changes that are available with the new backend:
      * unicode characters can now be rendered in the signature block when using TTF fonts
      * when using TTF fonts the new backend includes only a subset of used characters in the resulting document, which reduces the resulting size of the document
    * some minor bugs fixes

  * PDF-AS Web
    * some minor bugs fixes

* PDF-AS 4.0.11
  * First ECS Version
