.PHONY: all clean distclean print

all: final.pdf

final.pdf: final.tex ../custom.tex ../bibliography.bib style.sty
	pdflatex final
	bibtex final.aux
	pdflatex final
	pdflatex final

clean:
	@- $(RM) final.pdf final.aux final.bbl final.blg final.log final.nav final.out final.pdf final.snm final.toc final-print.pdf

distclean: clean

print: final-print.pdf

final-print.pdf: final.tex ../custom.tex ../bibliography.bib style.sty
	sed -r 's/ *\\pause/% &/' <final.tex >final-print.tex
	pdflatex final-print
	bibtex final-print.aux
	pdflatex final-print
	pdflatex final-print
	ls final-print.* | sed '/final-print.pdf/ d' | xargs rm
