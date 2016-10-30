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
    (master_doc, 'ecs-user-manual-de.tex', 'Ecs BenutzerInnen Handbuch',
     'Latex Author Name', 'howto'),
]
man_pages = [
    (master_doc, 'ecs-user-manual-de', 'Ecs BenutzerInnen Handbuch',
     [author], 1)
]
texinfo_documents = [
    (master_doc, 'ecs-user-manual-de', 'Ecs BenutzerInnen Handbuch',
     author, 'ecs-user-manual-de', 'Ethikkommission Verwaltung',
     'Miscellaneous'),
]
