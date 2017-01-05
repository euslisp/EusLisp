all:
	make toc dvi pdf


toc:
	makeindex jmanual.tex

dvi:
	platex --version | grep utf8 || nkf --in-place -e *.tex
	platex jmanual.tex
	platex jmanual.tex
	platex --version | grep utf8 || nkf --in-place -u *.tex

pdf:
	dvipdfmx jmanual.dvi


clean:
	rm -f *~ *.aux *.idx *.log *.toc *.out *.ind *.ilg

distclean: clean
	rm -f *.dvi *.pdf

html:
	rm -f ../html/jmanual*.
	TRANSPARENT_COLOR="#ffffff" charset="UTF-8" latex2html -dir ../html/ -transparent -local_icons -split +3 -auto_prefix -init_file ../latex/.latex2html-init -iso_language JP jmanual
	(cd ../html; sed -i 's@"jmanual.css"@"manual.css"@' j*.html)



