#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys

sys.path.append(os.path.join(os.getcwd(),".."))
from include.baseconf import *

project = 'ecs-admin-manual'
language = 'en'
latex_documents = [
    (master_doc, '{}.tex'.format(project), 'ECS Administration Manual',
     author, 'howto'),
]
