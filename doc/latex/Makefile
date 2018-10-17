manual:	arith.tex contact.tex controls.tex evaluation.tex generals.tex \
	geometry.tex graphics.tex image.tex intro.tex \
	io.tex manipulator.tex manual.tex \
	mars-pre.tex matrix.tex methods.tex  mthread.tex objects.tex \
	preface.tex sequences.tex  symbols.tex sysfunc.tex \
	types.tex voronoi.tex xtoolkit.tex xwindow.tex 
	(latex manual ; makeindex manual.idx; latex manual; dvipdfm manual.dvi >manual.pdf; \
	eus ../help.eus/makehelp.l "(progn (make-help) (quit))" )
manual2:
	latex manual ; dvips -o manual.ps manual.pdf
#	latex manual ; dvi2ps manual.dvi >manual.ps

html:
	rm -f ../html/manual*.{old,html,png,pl} ../html/manual-images.*
	TRANSPARENT_COLOR="#ffffff" latex2html -dir ../html/ -transparent -local_icons -split +3 -auto_prefix -iso_language JP manual


