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
	TRANSPARENT_COLOR="#ffffff" latex2html -dir ../html/ -transparent -local_icons -split +3 -auto_prefix -iso_language JP -html_version="4.0,unicode" manual
