all:
	make toc dvi pdf


toc:
	makeindex jmanual.tex

dvi:
	nkf --in-place -e *.tex
	platex jmanual.tex
	platex jmanual.tex
	nkf --in-place -u *.tex

pdf:
	dvipdfmx jmanual.dvi


clean:
	rm -f *~ *.aux *.idx *.log *.toc *.out *.ind *.ilg

distclean: clean
	rm -f *.dvi *.pdf

html:
	charset="UTF-8" latex2html -dir ../html/ -local_icons -auto_prefix -iso_language JP jmanual
	(cd ../html; sed -i 's@</TITLE>@</TITLE>\n<META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8">@' j*.html)



