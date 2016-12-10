#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys
import tinkerer
import tinkerer.paths

sys.path.append(os.path.join(os.getcwd(),".."))
from include.baseconf import *

project = 'ECS'
tagline = 'Ethics Committee System Development'
description = 'This is an awesome blog'
author = 'general author name'
copyright = '2017, ' + author
language = 'en'

# Change this to your blog root URL (required for RSS feed)
website = 'http://127.0.0.1/blog/html/'
# Link to RSS service like FeedBurner if any, otherwise feed is linked directly
rss_service = None
# Generate full posts for RSS feed even when using "read more"
rss_generate_full_posts = False
# Number of blog posts per page
posts_per_page = 10
# Character use to replace non-alphanumeric characters in slug
slug_word_separator = '_'
# Set to page under /pages (eg. "about" for "pages/about.html")
landing_page = 'about'
# Set to override the default name of the first page ("Home")
first_page_title = 'News'

extensions += ['tinkerer.ext.blog',]
exclude_patterns += ['drafts/*', '_templates/*']

html_theme= 'flat'
html_theme_options = {
}
html_logo = '_static/logo.png'
html_favicon = '_static/favicon.ico'
html_use_index = False
html_static_path = ['_static', tinkerer.paths.static]
html_theme_path = ['_themes', tinkerer.paths.themes]
html_sidebars = {
    #'**': ['recent.html', 'searchbox.html']
}


# **************************************************************
# Do not modify below lines as the values are required by
# Tinkerer to play nice with Sphinx
# **************************************************************
#source_suffix += tinkerer.source_suffix
master_doc = tinkerer.master_doc
version = tinkerer.__version__
release = tinkerer.__version__
html_title = project
html_show_sourcelink = False
html_add_permalinks = None
