all:
	make toc dvi pdf


toc:
	makeindex jmanual.tex

dvi:
	platex jmanual.tex
	platex jmanual.tex

pdf:
	dvipdfmx jmanual.dvi


clean:
	rm -f *~ *.aux *.idx *.log *.toc *.out *.ind *.ilg

distclean: clean
	rm -f *.dvi *.pdf