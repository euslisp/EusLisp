all:
	make manual help


manual:	arith.tex contact.tex controls.tex evaluation.tex generals.tex \
	geometry.tex graphics.tex image.tex intro.tex \
	io.tex manipulator.tex manual.tex \
	mars-pre.tex matrix.tex methods.tex  mthread.tex objects.tex \
	preface.tex sequences.tex  symbols.tex sysfunc.tex \
	types.tex voronoi.tex xtoolkit.tex xwindow.tex 
	(latex manual ; makeindex manual.idx; latex manual; dvipdfm manual.dvi >manual.pdf)

manual2:
	latex manual ; dvips -o manual.ps manual.pdf
#	latex manual ; dvi2ps manual.dvi >manual.ps

help:
	eus ../help.eus/makehelp.l "(let ((*eus-tex-dir* (pwd))) (make-help) (quit))"

clean:
	rm -f *~ *.aux *.idx *.log *.toc *.out *.ind *.ilg

distclean: clean
	rm -f *.dvi *.pdf

html:
	rm -f ../html/manual*.{old,html,png,pl} ../html/manual-images.*
	TRANSPARENT_COLOR="#ffffff" latex2html -dir ../html/ -transparent -local_icons -split +3 -auto_prefix -iso_language JP -address "This document was generated using the LaTeX2HTML translator on `date` from <a href=\"http://github.com/euslisp/EusLisp.git\">EusLisp</a> version <a href=\"http://github.com/euslisp/EusLisp/commit/`git rev-parse --verify HEAD`\">`git log -1  --oneline`</a>" -html_version="4.0,unicode" manual
	(cd ../html; for imgfile in manual-img*.png; do pngtopnm $$imgfile > /tmp/$$imgfile.pnm; pnmtopng -transparent white /tmp/$$imgfile.pnm > $$imgfile; done)

latex.py:
	wget https://raw.githubusercontent.com/jobh/latex.py/master/latex.py

#
TEXFILES=$(filter-out manual.tex, $(wildcard *.tex))
RSTFILES=$(TEXFILES:%.tex=%.rst)
%.rst : %.tex
	python3 latex.py -2 -L preamble.tex $< > /tmp/tmp_$^
	pandoc /tmp/tmp_$^ -o $@ -V documentclass=ltjarticle --latex-engine=lualatex
	sed -i 's@.. figure:: \(.*\).ps@.. figure:: \1.png@g' $@  # use png for figures

PSFILES=$(wildcard fig/*.ps)
PNGFILES=$(PSFILES:%.ps=%.png)
%.png : %.ps
	#ps2png $^ $@
	pstopnm -stdout $^ | pnmflip -rotate270 | pnmtopng - > $@


rst: manual.rst
manual.rst: latex.py $(RSTFILES) $(PNGFILES)
	cp manual.tex /tmp/manual.tex
	sed -i 's@\\input{\(.*\)}@..include:: \1\n@g' /tmp/manual.tex  # convert \input in tex to bypass pandoc
	sed -i 's@\\part{\(.*\)}@.. toctree:: \1@' /tmp/manual.tex  # convert \part in tex to bypass pandoc
	sed -i ':a;/^[^%].*\\\\$$/{N;s/\\\\\n//;ba}' /tmp/manual.tex # concatinate title/author multi lines
	sed -i '/^\\vspace{10mm}$$/d' /tmp/manual.tex # remove vspace{10mm} within title to pass pandoc
	pandoc --no-wrap -s /tmp/manual.tex -o manual.rst -V documentclass=ltjarticle --latex-engine=lualatex
	sed -i 's@..include:: \(.*\)@   \1@' manual.rst # restore ..include for rst
	sed -i 's@.. toctree:: \(.*\)@.. toctree::\n   :maxdepth: 1\n   :caption: \1@' manual.rst  # restore ..toctree for rst
	sed -i 's@** Featuring@**\nFeaturing@' manual.rst # add newline before Featuring in title
	sed -i -ne '3!{p;d;};h;n;:1;4!{N;b1};G;h;n;p;g;p' manual.rst; head manual.rst

