#!/bin/bash

rm -rf _build
mkdir -p _build

for i in `find . -name "conf.py"`; do
  j=$(dirname $i)
  j=${j:2}
  cd $j
  make clean html latexpdf
  mv	_build/html/ ../_build/$j/
  mv  _build/latex/$j.pdf ../_build/
  cd ..
done
