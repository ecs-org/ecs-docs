#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys

sys.path.append(os.path.join(os.getcwd(),".."))
from include.baseconf import *

project = 'ecs-admin-manual'
author = 'general author name'
version = '2'
release = '0 TODO:use git id'
language = 'en'
latex_documents = [
    (master_doc, '{}.tex'.format(project), 'ECS Administration Manual',
     'Latex Author Name', 'howto'),
]
