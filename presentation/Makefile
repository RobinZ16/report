TeX_sources := $(wildcard *.tex)
objects := $(TeX_sources:.tex=.pdf)

.PHONY: all clean distclean

all: $(objects)

$(objects): %.pdf: %.tex
	pdflatex $<
	pdflatex $<

clean:
	@- $(RM) $(objects) $(objects:.pdf=.log) $(objects:.pdf=.out) $(objects:.pdf=.aux)

distclean: clean
