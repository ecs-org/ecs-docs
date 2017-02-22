#!/usr/bin/env python
# -*- coding: utf-8 -*- #
from __future__ import unicode_literals
import os

AUTHOR = '2017 Medizinische Universität Wien, Medizinische Universität Innsbruck, Medizinische Universität Graz, Johannes Kepler Universität Linz, Karl Landsteiner Privatuniversität für Gesundheitswissenschaften'
SITENAME = 'ECS - Ethics Committee System'
SITEURL = ''
#THEME = 'simple'
THEME = '_themes/pelican-bootstrap3'
PLUGIN_PATHS = [
    os.path.abspath(os.path.join(os.path.dirname(__file__), '_plugins')),
  ]
PLUGINS = ['i18n_subsites']
JINJA_ENVIRONMENT = {'extensions': ['jinja2.ext.i18n']}

OUTPUT_SOURCES = False
OUTPUT_PATH = '_build'
PATH = '.'
PAGE_PATHS = ['pages']
ARTICLE_PATHS = ['articles']
STATIC_PATHS = ['static']

DEFAULT_LANG = 'en'
DEFAULT_DATE = 'fs'
DEFAULT_PAGINATION = False
DEFAULT_DATE_FORMAT = '%a %d %B %Y'
TIMEZONE = 'Europe/Paris'
TYPOGRIFY = False

PAGE_ORDER_BY = 'order' # use meta tag order to define pages order

# Menu
DISPLAY_PAGES_ON_MENU = True # do not display, because we want to override all
DISPLAY_CATEGORIES_ON_MENU = False
# A list of tuples (Title, URL) for additional menu items to appear at the beginning of the main menu.
MENUITEMS = (
#    ( 'Custom', '#'),
)

# Links
# A list of tuples (Title, URL) for links to appear on the header.
LINKS = (
#    ( 'Test Header Link', '#'),
)
# A list of tuples (Title, URL) to appear in the “social” section.
SOCIAL = (
#    ('Test Social Link', '#'),
)

# Tags are not needed
TAGS_SAVE_AS = ''
TAG_SAVE_AS = ''

# Feed generation is not needed
FEED_ALL_ATOM = None
CATEGORY_FEED_ATOM = None
TRANSLATION_FEED_ATOM = None
AUTHOR_FEED_ATOM = None
AUTHOR_FEED_RSS = None

# Article info is not needed
SHOW_ARTICLE_AUTHOR = False
SHOW_ARTICLE_CATEGORY = False
SHOW_DATE_MODIFIED = False

# Add custom CSS
CUSTOM_CSS = 'static/custom.css'

# Theme options
HIDE_SIDEBAR = True
BOOTSTRAP_NAVBAR_INVERSE = True