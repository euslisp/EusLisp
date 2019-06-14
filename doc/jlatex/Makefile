all:
	make toc dvi pdf help


toc:
	makeindex jmanual.tex

dvi:
	platex --version | grep utf8 || nkf --in-place -e *.tex
	platex jmanual.tex
	platex jmanual.tex
	platex --version | grep utf8 || nkf --in-place -u *.tex

pdf:
	dvipdfmx jmanual.dvi

help:
	eus ../help.eus/makehelp.l "(let ((*eus-jtex-dir* (pwd))) (make-jhelp) (quit))"

clean:
	rm -f *~ *.aux *.idx *.log *.toc *.out *.ind *.ilg

distclean: clean
	rm -f *.dvi *.pdf

html:
	rm -f ../html/jmanual*.
	TRANSPARENT_COLOR="#ffffff" charset="UTF-8" latex2html -dir ../html/ -transparent -local_icons -split +3 -auto_prefix -init_file ../latex/.latex2html-init -iso_language JP -address "This document was generated using the LaTeX2HTML translator on `date` from <a href=\"http://github.com/euslisp/EusLisp.git\">EusLisp</a> version <a href=\"http://github.com/euslisp/EusLisp/commit/`git rev-parse --verify HEAD`\">`git log -1  --oneline`</a>" -html_version="4.0,unicode" jmanual
	(cd ../html; sed -i 's@"jmanual.css"@"manual.css"@' j*.html)
	(cd ../html; for imgfile in jmanual-img*.png; do pngtopnm $$imgfile > /tmp/$$imgfile.pnm; pnmtopng -transparent white /tmp/$$imgfile.pnm > $$imgfile; done)


