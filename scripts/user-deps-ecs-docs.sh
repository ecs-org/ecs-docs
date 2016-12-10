#!/bin/bash

srcpath="$(readlink -e $(dirname $(readlink -e "$0"))/..)"
envdir=${1:-$srcpath/_env}
python3 -m venv $envdir
. $envdir/bin/activate
pip install sphinx recommonmark tinkerer sphinxcontrib-actdiag sphinxcontrib-blockdiag sphinxcontrib-nwdiag sphinxcontrib-plantuml sphinxcontrib-programoutput sphinxcontrib-seqdiag sphinxcontrib.youtube sphinxcontrib-inlinesyntaxhighlight

# additional extensions: sphinx-argparse changelog releases
