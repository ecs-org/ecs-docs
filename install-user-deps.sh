#!/bin/bash

# as user
envdir=${1:-~/envdocs}
python3 -m venv $envdir
. $envdir/bin/activate
pip install sphinx recommonmark sphinxcontrib-actdiag sphinxcontrib-blockdiag sphinxcontrib-nwdiag sphinxcontrib-plantuml sphinxcontrib-programoutput sphinxcontrib-seqdiag sphinxcontrib.youtube sphinxcontrib-inlinesyntaxhighlight

# additional extensions: sphinx-argparse changelog releases
