all:
	-svn del --force *.html *.png
	-rm -fr *aux *.log *.pl *.tex *.old *.css *.idx WARNINGS
	-(cd ../latex; make html)
	-(cd ../jlatex; make html)
	-rm index.html
	-svn add *.html *.png

