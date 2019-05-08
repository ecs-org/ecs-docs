# Digital signed pdf documents

The ECS uses Mocca and PDF-AS to create digital signed pdf documents.

Mocca and PDF-AS are developed by EGIZ, the eGovernment Innovation Centre of Austria, a joint initiative of the Federal Chancellery and the Graz University of Technology, at the Institute for Applied Information Processing and Communications Technology (IAIK).

* [EGIZ Mocca - a modular, open source citizen card environment](http://www.egiz.gv.at/en/schwerpunkte/9-MOCCA)
* [EGIZ PDF-AS - a java framework for creating digitial signatures on PDF documents](http://www.egiz.gv.at/en/schwerpunkte/16-pdf-as)

## Mocca

* Current Frozen (onlineBKU) Release: [Mocca 1.3.27 (2017-06-23)](https://joinup.ec.europa.eu/release/mocca-1327)
* Next Version (localBKU) Release: [Mocca 1.4.1 (2019-05-07)](https://joinup.ec.europa.eu/release/mocca/141)
* [Mocca WebStart from buergerkarte.at](https://webstart.buergerkarte.at/mocca/index.html)
    * [Install](https://webstart.buergerkarte.at/mocca/webstart/mocca.jnlp)
    * [CA Install from local running BKU](http://localhost:3495/ca.crt)
    * [Test](https://www.buergerkarte.at/test-suite-karte.html)

* [Security Analysis of the Austrian Citizen Card Environment MOCCA and E-Card](https://www.auto.tuwien.ac.at/bib/pdf_TR/TR0174.pdf)
* [MOCCA Usability Analyse](https://www.egiz.gv.at/files/download/Studie.pdf)


### Download
  * Online BKU: [Mocca 1.3.27 - bkuonline-1.3.27.war](https://joinup.ec.europa.eu/sites/default/files/distribution/2017-06/bkuonline-1.3.27.war)
  * Local BKU: [Mocca 1.4.1 - Release Directory](https://apps.egiz.gv.at/releases/mocca/1.4.1/)

```
sha256=c3a7270294bc3a43790061e9eec059ef6a124eb3bd55d20edfd8a7b6b6b89b23  bkuonline-1.3.27.war
```
  
* Sourcecode:
  * [http://git.egiz.gv.at/mocca](http://git.egiz.gv.at/mocca)

### Changes
* MOCCA 1.4.1 - 2019-05-07
    * Update TrustStore and CertStore (The following Certificates were added to MOCCA):
        * D-TRUST Root Class 3 CA 2 EV 2009
        * D-TRUST CA 2-2EV 2016
        * Thwate RSA CA 2018
        * RapidSSL RSA CA 2018
    * The BKU icon was updated
* MOCCA 1.4.0 - 2018-09-25
    * Update of PKI-Module and the CertSore to the latest version
    * Changes to build standalone-installer for Java Version 11 and later
        * Standalone installer for Windows (MSI), MacOS (DMG) and Linux (ZIP) are now available.
    * New MOCCA update mechanism:
        * MOCCA verifies now during startup if there is a newer version available and notifies the user if this is the case.
    * Update of security-relevant libraries
* MOCCA 1.3.34 - 2018-08-30
    * New Certificates in the truststore:
        * DSTRootCAX3
        * DigiCertGlobalRootG2
    * New Certificates in the certstore:
        * GeoTrustRSACA2018
        * ThwateTLSRSACAG1
* MOCCA 1.3.33 - 2018-05-15
    * Bulk Signature Branch merged into Master Branch 
    * Small Bug Fix: Error code 2000 when using Java 8 
* MOCCA 1.3.32 - 2018-04-20 
    * BKUCertificates updated
        * New certificated added to certstore for secure.gesundheit.gv.at
        * Letsencrypt root ca added to truststore
* MOCCA 1.3.31 - 2018-02-07
    * Small bug fix in the Request GetInfoBox
    * Support for Java 9
* MOCCA 1.3.30 - 2018-01-15
    * Certificate update
* MOCCA 1.3.29 - 2017-08-28
    * Library Update
    * Included PAdES signature
    * Certificate update
* MOCCA 1.3.28 - 2017-07-26
    * Library Update
    * Removed bkuonline support
* MOCCA 1.3.27 - 2017-06-23
    * Last bkuonline support 
    * Security Bugfix
* MOCCA 1.3.26 - 2017-05-29
    * New card implementation (A-Trust signature card CardOSV5.3)
* MOCCA 1.3.25 - 2017-05-08
    * MOCCA Library Update
    * Bugfix
* MOCCA 1.3.24 - 2016-12-01
    * Fixed problem, which occured when using MOCCA together with MOA-ID in a single webapp container.
    * System-Properties include now the prefix ".jnlp"
* MOCCA 1.3.23 - 2016-03-31
    * First ECS Version

## PDF-AS

* Current Frozen (onlineBKU) Release:
    * [PDF-AS 4.1.0 (2017-01-17)](https://joinup.ec.europa.eu/release/pdf-410)
    * [PDF-AS defaultConfig 4.1.1 (2017-08-29)](https://joinup.ec.europa.eu/release/pdf/411)
* Next Version (localBKU) Release: [PDF-AS 4.1.5 (2018-12-07)](https://joinup.ec.europa.eu/release/pdf/415)
    * [Documenation - DE](https://apps.egiz.gv.at/releases/pdf-as/release/4.1.5/docs/PDFAS4_Dokumentation.pdf)
    * [Web Interface Documenation - DE](https://apps.egiz.gv.at/releases/pdf-as/release/4.1.5/docs/PDFAS4_WebDokumentation.pdf)
    * [External Service Documentation - DE](https://apps.egiz.gv.at/releases/pdf-as/release/4.1.5/docs/AnbindungExterneWebanwendung.pdf)
    * [Profile Documentation -  DE](https://apps.egiz.gv.at/releases/pdf-as/release/4.1.5/docs/PDFAS4_Profile_Dokumentation.pdf)
* [Goverment Profile Documentation - DE](https://www.ref.gv.at/uploads/media/Layout_Amtssignatur_las_2-0-1_20140610.pdf)
* [PDF-AS Workshop Part 1 - DE](http://demo.egiz.gv.at/padesWorkshop/20141209%20Signatur-Workshop-PDF-AS-4.0-Hands-On%20Teil1.pdf)
* [PDF-AS Workshop Part 2 - DE](http://demo.egiz.gv.at/padesWorkshop/20141209%20Signatur-Workshop-PDF-AS-4.0-Hands-On%20Teil2.pdf)
* [Goverment sponsored Digital Signature Test Site - DE](https://www.buergerkarte.at/einfach-signieren/)

### Download
* [Download Site](https://apps.egiz.gv.at/releases/pdf-as/release/4.1.5/)

* Current 4.1.5 [pdf-as-web-4.1.5.war](https://apps.egiz.gv.at/releases/pdf-as/release/4.1.5/pdf-as-web-4.1.5.war)
```
sha256=a54f3dd8c77e5d7ef47b05465143b09014dfd802240e557f39aaaf7c9fb2d518  pdf-as-web-4.1.5.war
```
* Current 4.1.5 [defaultConfig.zip](https://apps.egiz.gv.at/releases/pdf-as/release/4.1.5/cfg/defaultConfig.zip)
```
sha256= 22a73c4a45fb44f6a0a30db9a95a5cb5ef3b5ee4e14ca768e3ebb15f5597813f  defaultConfig.zip
```

* old frozen 4.1.0 [pdf-as-web-4.1.0.war](https://ecs-org.github.io/ecs-docs/pdf-as-web-4.1.0.war)
```
sha256=d625cd40a0baadf9ccf2a9bb46f6808efb7929e3fbe107b087b8c42f5b6c1971  pdf-as-web-4.1.0.war
```
* old frozen 4.1.1 [defaultConfig-4.1.1.zip](https://ecs-org.github.io/ecs-docs/defaultConfig-4.1.1.zip)
```
sha256=392718b4b8e57582ec529061c25437b3858574a90214e429069cbc084333ca8d  defaultConfig-4.1.1.zip
```

  
* Sourcecode:
  * [http://git.egiz.gv.at/pdf-as-4/](http://git.egiz.gv.at/pdf-as-4/)

### Changes

* PDF-AS 4.1.5 - 2018-12-07
    * Beta state of the Security Layer 2.0 functionality has been added
    * Bug fixes regarding positioning feature (positioning with a "footer" paramter, positioning with a "page" parameter)
* PDF-AS 4.1.4 - 2018-06-27
    * PDF-AS Library
        * Color profile for PDFA added
* PDF-AS 4.1.3 - 2018-05-14
    * Minor bug fixes
* PDF-AS 4.1.2 - 2018-03-23
    * Minor bug fixes
    * Additional feature regarding placeholder search
    * Pdf file protection
* PDF-AS 4.1.1 - 2017-08-29
    * Minor bug fixes
    * Changes for PAdES signatures
    * Library Update
    * Removed bkuonline support
* PDF-AS 4.1.0 - 2017-01-17
    * Last bkuonline support
    * PDF-AS Library
        * a new pdf backend is available based on pdfbox 2.0.3, changes that are available with the new backend:
        * unicode characters can now be rendered in the signature block when using TTF fonts
        * when using TTF fonts the new backend includes only a subset of used characters in the resulting document, which reduces the resulting size of the document
        * some minor bugs fixes
    * PDF-AS Web
        * some minor bugs fixes
* PDF-AS 4.0.11 - 2016-07-01
    * First ECS Version

## Mobile Signature (aka "Handy Signatur") from A-Trust

* [Technical Documentation](https://labs.a-trust.at/developer/pdf/SignatureServer_1.2.2.pdf)

