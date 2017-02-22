#!/bin/bash

srcpath="$(readlink -e $(dirname $(readlink -e "$0"))/..)"
envdir=${1:-$srcpath/_env}
python3 -m venv $envdir
. $envdir/bin/activate
pip install sphinx recommonmark ghp-import pelican markdown typogrify sphinx-better-theme sphinxcontrib-actdiag sphinxcontrib-blockdiag sphinxcontrib-nwdiag sphinxcontrib-plantuml sphinxcontrib-programoutput sphinxcontrib-seqdiag sphinxcontrib.youtube sphinxcontrib-inlinesyntaxhighlight 
# additional extensions: sphinx-argparse changelog releases

# clone all themes and plugins of pelican to subdir of homepage
git clone https://github.com/getpelican/pelican-themes.git $srcpath/homepage/_themes
git clone --recursive https://github.com/getpelican/pelican-plugins $srcpath/homepage/_plugins
