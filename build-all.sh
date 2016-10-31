#!/bin/bash

rm -rf _build
mkdir -p _build

for i in ecs-admin-manual ecs-user-manual-de ecs-test-doc; do
  cd $i
  make clean html latexpdf
  mv	_build/html/ ../_build/$i/
  mv  _build/latex/$i.pdf ../_build/
  cd ..
done
