all: 
	echo "make [main|print]"

main:
	pdflatex main
	pdflatex main

print:	main
	pdfjam --a4paper --nup 2x2 --landscape --scale 1 --outfile main-2x2.pdf main.pdf

pres:
	pdflatex Cours-Présentation.tex
	pdflatex Cours-Présentation.tex

clean:
	-rm main.aux main.log main.nav main.out main.snm main.toc
	-rm Cours-Présentation.aux Cours-Présentation.log Cours-Présentation.nav Cours-Présentation.out Cours-Présentation.snm Cours-Présentation.toc
