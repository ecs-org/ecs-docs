# ECS-Documentation

+ Documentation is written using sphinx
+ Sourcefiles can be restructured text and markdown.
  + markdown support using https://github.com/rtfd/recommonmark
+ HTML and PDF documentation is generated as output
  + latex is used to generate pdfs
+ Html Theme: Alabaster http://alabaster.readthedocs.io/en/latest/customization.html
+ Blog Html Theme: tinkerer flat
+ Available graph support
  + plantuml, graphviz with cpp support, actdiag, nwdiag, seqdiag, blockdiag
+ Additional available sphinx extensions
  + sphinxcontrib-programoutput sphinxcontrib.youtube sphinxcontrib-inlinesyntaxhighlight

## Howto write Restructured Text or Markdown
  Look in [rest-cheatsheet.rst](ecs-test-doc/src/rest-cheatsheet.rst) and [markdown-cheatsheet.md](ecs-test-doc/src/markdown-cheatsheet.md)
  what works by looking at both source and output html/pdf

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
sudo os-deps-ecs-docs.sh
user-deps-ecs-docs.sh
```

### build
```
build-all-ecs-docs.sh
firefox _build/*/html/index.html
evince _build/*/latex/ecs*.pdf
```

### build and update gh-pages branch
```
update-gh-pages-branch.sh
```
