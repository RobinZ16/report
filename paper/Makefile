TeX_sources := $(wildcard *.tex)

.PHONY: all clean distclean

all: paper.pdf

paper.pdf: $(TeX_sources) ../preamble.tex ../custom.tex ../bibliography.bib
	pdflatex paper
	bibtex paper
	pdflatex paper
	pdflatex paper

clean:
	@- $(RM) paper.pdf $(TeX_sources:.tex=.aux) $(TeX_sources:.tex=.log) $(TeX_sources:.tex=.out) $(TeX_sources:.tex=.toc) $(TeX_sources:.tex=.bbl) $(TeX_sources:.tex=.blg)

distclean: clean
