#!/bin/bash
srcpath="$(readlink -e $(dirname $(readlink -e "$0"))/..)"

cd $srcpath
. _env/bin/activate
if ! scripts/build-all-ecs-docs.sh; then
    echo "Error: build-all-ecs-docs failed"
    exit 1
fi

ghp-import -r origin -b gh-pages -m "regenerate docs" -p $srcpath/_build/
