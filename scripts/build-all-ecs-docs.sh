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

echo "homepage build is disabled"

cd $srcpath/homepage
#rm -rf blog/*
#tinker -b
#mv blog/html/ $srcpath/_build/homepage
pelican 

cd $srcpath/_build
> .nojekyll
printf "%b" "FROM nginx\nCOPY . /usr/share/nginx/html\n" > Dockerfile
printf "%b" '<!doctype html>\n<html>\n<head>\n<meta http-equiv="REFRESH" content="0; url=./homepage/index.html" />\n<title></title>\n</head>\n<body></body>\n</html>\n' > index.html
