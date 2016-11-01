#!/bin/bash

srcpath="$(readlink -e $(dirname $(readlink -e "$0"))/..)"
cd $srcpath
# build all to _build
scripts/build-all-ecs-docs.sh

# hard update ./dist on gh-pages branch from current _build
rm -rf /tmp/ecs-dist
cp -r _build /tmp/ecs-dist
git checkout gh-pages
git pull
git reset
rm -rf dist
mv /tmp/ecs-dist dist
> dist/.gitkeep
printf "%b" "FROM nginx\nCOPY dist /usr/share/nginx/html\n" > Dockerfile
git add Dockerfile
git add --all dist
git commit -a -m "Update doc"
git push
git checkout master
