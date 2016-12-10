#!/bin/bash

srcpath="$(readlink -e $(dirname $(readlink -e "$0"))/..)"
cd $srcpath
rm -rf _build
mkdir -p _build
. _env/bin/activate

for d in user-manual-de admin-manual development; do
    make -C $d clean html latexpdf
    if test $? -ne 0; then
        echo "Error: building of $d failed"
        exit 1
    fi
    mv $d/_build/html/ _build/$d
    mv $d/_build/latex/ecs-$d.pdf _build/
done

cd $srcpath/homepage
rm -rf blog/*
tinker -b
mv blog/html/ $srcpath/_build/homepage
