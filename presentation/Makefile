TeX_sources := $(wildcard *.tex)
objects := $(TeX_sources:.tex=.pdf)

.PHONY: all clean distclean

all: $(objects)

presentation-0.pdf: presentation-0.tex
	pdflatex $<

presentation-1.pdf: presentation-1.tex
	pdflatex $<

presentation-2.pdf: presentation-2.tex
	pdflatex $<

final.pdf: final.tex ../custom.tex ../bibliography.bib style.sty
	pdflatex final
	bibtex final.aux
	pdflatex final
	pdflatex final

clean:
	@- $(RM) $(TeX_sources:.tex=.pdf) $(TeX_sources:.tex=.aux) $(TeX_sources:.tex=.log) $(TeX_sources:.tex=.out) $(TeX_sources:.tex=.toc) $(TeX_sources:.tex=.bbl) $(TeX_sources:.tex=.blg)

distclean: clean
