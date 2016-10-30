
extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.ifconfig',
    'sphinx.ext.viewcode',
    'sphinx.ext.githubpages',
    'sphinx.ext.graphviz',
]

project = 'ecs-user-manual-de'
copyright = '2016, EK-Meduniwien, EK-Medunigraz, EK-Meduniinnsbruck, EK-Linz, EK-Kepler'
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
