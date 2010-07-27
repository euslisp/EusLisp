manual:	arith.tex contact.tex controls.tex evaluation.tex generals.tex \
	geometry.tex graphics.tex image.tex intro.tex \
	io.tex manipulator.tex manual.tex \
	mars-pre.tex matrix.tex methods.tex  mthread.tex objects.tex \
	preface.tex sequences.tex  symbols.tex sysfunc.tex \
	types.tex voronoi.tex xtoolkit.tex xwindow.tex 
	(latex manual ; makeindex manual.idx; latex manual; \
		dvi2ps manual.dvi >manual.ps)
manual2:
	latex manual ; dvips -o manual.ps manual.dvi
#	latex manual ; dvi2ps manual.dvi >manual.ps

