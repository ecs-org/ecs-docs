#!/bin/bash

for i in ecs-operators-handbook ecs-user-manual-de ecs-test-doc; do
  cd $i
  make clean html latexpdf
  mv	_build/html/ ../dist/$i/
  mv  _build/latex/$i.pdf ../dist/
  cd ..
done
