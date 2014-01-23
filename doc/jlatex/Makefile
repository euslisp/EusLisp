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

html:
	nkf --in-place -e *.tex
	latex2html -dir ../html/ -local_icons -auto_prefix -iso_language JP jmanual
	nkf --in-place -j *.tex
	(cd ../html; nkf --in-place -s jmanual*.html)


