#!/bin/bash

srcpath="$(readlink -e $(dirname $(readlink -e "$0"))/..)"
cd $srcpath
rm -rf _build
mkdir -p _build
. _env/bin/activate

for d in `dirname */conf.py`; do
    make -C $d clean html latexpdf
    mv $d/_build/html/ ../_build/ecs-$d
    mv $d/_build/latex/ecs-$d.pdf ../_build/
done
