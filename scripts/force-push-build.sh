#!/bin/bash
srcpath="$(readlink -e $(dirname $(readlink -e "$0"))/..)"

# build all to _build
if ! scripts/build-all-ecs-docs.sh; then
    echo "Error: build-all-ecs-docs failed"
    exit 1
fi
ECS_HOMEPAGE_GIT_SOURCE="${ECS_HOMEPAGE_GIT_SOURCE:-ssh://git@gogs.omoikane.ep3.at:10022/ecs/ecs-homepage.git}"

cd  $srcpath/_build
> .nojekyll
printf "%b" "FROM nginx\nCOPY . /usr/share/nginx/html\n" > Dockerfile
printf "%b" "<!doctype html>\n<html>\n<head>\n<meta http-equiv="REFRESH" content="0; url=./homepage/index.html" />\n<title></title>\n</head>\n<body></body>\n</html>\n" > index.html
git init
git add --all .
git commit -a -m "Update doc"
git remote add origin $ECS_HOMEPAGE_GIT_SOURCE
git push -f origin master
