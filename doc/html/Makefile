all:
	-rm -fr *.aux *.log *.pl *.tex *.old *.css *.idx WARNINGS *.html *.png
	sed -i 's@^\(\\\usepackage.*{hyperref}\)@%\1@' ../latex/manual.tex
	sed -i 's@^\(\\\usepackage.*{hyperref}\)@%\1@' ../jlatex/jmanual.tex
	sed -i 's@\\\documentclass\[\]{jarticle}@\\\documentclass\[\]{article}@' ../jlatex/jmanual.tex
	sed -i 's@^\\\ifnum 42146@%\\\ifnum 42146@' ../jlatex/jmanual.tex
	(cd ../latex; git diff manual.tex)
	(cd ../jlatex; git diff jmanual.tex)
	(cd ../latex;  make html; make html)
	(cd ../jlatex; make html; make html)
	sed -i 's@%\(\\\usepackage.*{hyperref}\)@\1@' ../latex/manual.tex
	sed -i 's@%\(\\\usepackage.*{hyperref}\)@\1@' ../jlatex/jmanual.tex
	sed -i 's@\\\documentclass\[\]{article}@\\\documentclass\[\]{jarticle}@' ../jlatex/jmanual.tex
	sed -i 's@^%\\\ifnum 42146@\\\ifnum 42146@' ../jlatex/jmanual.tex
	-(cd ../latex; git diff manual.tex)
	-(cd ../jlatex; git diff jmanual.tex)
	-rm -fr *.aux *.log *.pl *.tex *.old *.css *.idx WARNINGS index.html

