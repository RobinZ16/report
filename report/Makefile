TeX_sources := $(wildcard *.tex) bibliography.bib

.PHONY: all clean distclean

all: report.pdf

report.pdf: $(TeX_sources)
	pdflatex report
	bibtex report
	pdflatex report
	pdflatex report

clean:
	@- $(RM) report.pdf $(TeX_sources:.tex=.aux) $(TeX_sources:.tex=.log) $(TeX_sources:.tex=.out) $(TeX_sources:.tex=.toc) $(TeX_sources:.tex=.bbl) $(TeX_sources:.tex=.blg)

distclean: clean
