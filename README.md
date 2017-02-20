# ECS-Documentation

+ Documentation is written using sphinx
+ Sourcefiles can be restructured text and markdown
  + markdown support using https://github.com/rtfd/recommonmark
+ HTML and PDF documentation is generated as output
  + latex is used to generate pdfs
  + Html Theme is Alabaster http://alabaster.readthedocs.io/en/latest/customization.html
+ The Blog (homepage) is rendered using tinkerer/sphinx and Html Theme: flat
+ Available graph support
  + plantuml, graphviz with cpp support, actdiag, nwdiag, seqdiag, blockdiag
+ Additional available sphinx extensions
  + sphinxcontrib-programoutput sphinxcontrib.youtube sphinxcontrib-inlinesyntaxhighlight

## Quickstart

### install

#### clone ecs-docs source
if you are ok with `~/ecs-docs`:

```
cd ~/
git clone replace-with-actual-url ecs-docs
```

somewhere else:

```
git clone replace-with-actual-url targetdirectoryyouwant/ecs-docs
ln -sft ~/ targetdirectoryyouwant/ecs-docs
```

#### setup
```
ln -sft ~/bin ~/ecs-docs/scripts/*
sudo scripts/os-deps-ecs-docs.sh
scipts/user-deps-ecs-docs.sh
```

### build
```
build-all-ecs-docs.sh
firefox _build/*/html/index.html
evince _build/ecs*.pdf
```

### build only user-manual-de
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
