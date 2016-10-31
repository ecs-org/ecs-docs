# ECS-Documentation

+ Documentation is written using sphinx
+ Sourcefiles can be restructured text and markdown.
  + markdown support using https://github.com/rtfd/recommonmark
+ HTML and PDF documentation is generated as output
  + latex is used to generate pdfs
+ Html Theme: Alabaster http://alabaster.readthedocs.io/en/latest/customization.html
+ Available graph support
  + plantuml, graphviz with cpp support, actdiag, nwdiag, seqdiag, blockdiag
+ Additional available sphinx extensions
  + sphinxcontrib-programoutput sphinxcontrib.youtube sphinxcontrib-inlinesyntaxhighlight


## Quickstart

```
sudo install-os-deps.sh
install-user-deps.sh
build-all
firefox _build/*/html/index.html
evince _build/*/latex/ecs*.pdf
```
