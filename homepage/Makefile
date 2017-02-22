# Makefile 

BUILDDIR = _build

.PHONY: help
help:
	@echo 'Makefile for a pelican Web site'
	@echo ''
	@echo 'Usage:'
	@echo '   make html                           (re)generate the web site  '
	@echo '   make clean                          remove the generated files '

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)/*

.PHONY: html
html:
	pelican --relative-urls
	printf "%b" '<!doctype html>\n<html>\n<head>\n<meta http-equiv="REFRESH" content="0; url=./pages/about.html" />\n<title></title>\n</head>\n<body></body>\n</html>\n' > _build/index.html

