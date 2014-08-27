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
	nkf --in-place -u *.tex
	charset="UTF-8" latex2html -dir ../html/ -local_icons -auto_prefix -iso_language JP jmanual
	nkf --in-place -j *.tex
	(cd ../html; sed -i 's@</TITLE>@</TITLE>\n<META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8">@' j*.html)



