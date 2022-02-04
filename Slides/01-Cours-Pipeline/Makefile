all: 
	echo "make [main|pres|print]"

main:
	pdflatex main
	pdflatex main

print:	main
	pdfnup --a4paper --nup 1x4 --offset "-4cm 0cm" --frame true --scale 1 --no-landscape --outfile main-1x4.pdf main.pdf

clean:
	-rm main.aux main.log main.nav main.out main.snm main.toc

