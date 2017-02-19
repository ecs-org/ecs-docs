#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys

sys.path.append(os.path.join(os.getcwd(),".."))
from include.baseconf import *

project = 'ecs-user-manual-de'
author = 'general author name'
version = '2'
release = '0 TODO:use git id'
language = 'de'
latex_documents = [
    (master_doc, '{}.tex'.format(project), 'Ecs BenutzerInnen Handbuch',
     'Latex Author Name', 'howto'),
]
html_favicon = '_static/favicon.ico'
html_show_sphinx = False
