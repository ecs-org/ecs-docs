#!/bin/bash
srcpath="$(readlink -e $(dirname $(readlink -e "$0"))/..)"

cd $srcpath
. _env/bin/activate
if ! scripts/build-all-ecs-docs.sh; then
    echo "Error: build-all-ecs-docs failed"
    exit 1
fi
ghp_remote="origin"
ghp_branch="gh-pages"

ghp-import -r $ghp_remote -b $ghp_branch -m "regenerate docs" $srcpath/_build/
