#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys

sys.path.append(os.path.join(os.getcwd(),".."))
from include.baseconf import *

project = 'ecs-operators-handbook'
author = 'general author name'
version = '2'
release = '0 TODO:use git id'
language = 'en'
latex_documents = [
    (master_doc, 'ecs-operators-handbook.tex', 'ECS Operator\'s Handbook',
     'Latex Author Name', 'howto'),
]
man_pages = [
    (master_doc, 'ecs-operators-handbook', 'ECS Operator\'s Handbook',
     [author], 1)
]
texinfo_documents = [
    (master_doc, 'ecs-operators-handbook', 'ECS Operator\'s Handbook',
     author, 'ecs-operators-handbook', 'EthicsCommission Administration',
     'Miscellaneous'),
]
