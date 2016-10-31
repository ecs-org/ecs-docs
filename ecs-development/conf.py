#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys

sys.path.append(os.path.join(os.getcwd(),".."))
from include.baseconf import *

project = 'ecs-development' # fixme get current directory name as project
author = 'general author name'
version = '2'
release = '0 TODO:use git id'
language = 'en'
latex_documents = [
    (master_doc, '{}.tex'.format(project), 'ECS Development Documentation',
     'Latex Author Name', 'howto'),
]
