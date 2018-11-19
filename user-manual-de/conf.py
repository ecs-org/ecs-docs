#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys

sys.path.append(os.path.join(os.getcwd(),".."))
from include.baseconf import *

project = 'ecs-user-manual-de'
html_short_title = "ECS Benutzer-Handbuch"
language = 'de'
latex_documents = [
    (master_doc, '{}.tex'.format(project), 'Ecs BenutzerInnen Handbuch',
     'Latex Author Name', 'howto'),
]

