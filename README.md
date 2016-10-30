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


:build-static content selfserved

  FROM nginx
  COPY ecs-operators-handbook/_build/html /usr/share/nginx/html/ecs-operators-handbook
  COPY ecs-user-manual-de/_build/html /usr/share/nginx/html/ecs-user-manual-de

  copy some index files to /usr/share/nginx/html
  done!
