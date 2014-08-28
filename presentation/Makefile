TeX_sources := $(wildcard *.tex)
objects := $(TeX_sources:.tex=.pdf)

.PHONY: all clean distclean print

all: $(objects)

presentation-0.pdf presentation-1.pdf presentation-2.pdf notes.pdf: %.pdf : %.tex
	pdflatex $<
	pdflatex $<

final.pdf: final.tex ../custom.tex ../bibliography.bib style.sty
	pdflatex final
	bibtex final.aux
	pdflatex final
	pdflatex final

clean:
	@- $(RM) $(TeX_sources:.tex=.pdf) $(TeX_sources:.tex=.aux) $(TeX_sources:.tex=.log) $(TeX_sources:.tex=.out) $(TeX_sources:.tex=.toc) $(TeX_sources:.tex=.bbl) $(TeX_sources:.tex=.blg)

distclean: clean

print: final-print.pdf

final-print.pdf: final.tex ../custom.tex ../bibliography.bib style.sty
	sed -r 's/ *\\pause/% &/' <final.tex >final-print.tex
	pdflatex final-print
	bibtex final-print.aux
	pdflatex final-print
	pdflatex final-print
	ls final-print.* | sed '/final-print.pdf/ d' | xargs rm
