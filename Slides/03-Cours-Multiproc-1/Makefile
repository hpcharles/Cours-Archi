
slides: main.tex
	pdflatex main
	pdflatex main

print:	slides
	pdfnup --a4paper --nup 1x4 --offset "-3cm 0cm" --frame true --scale 1 --no-landscape --outfile main-1x4.pdf main.pdf

SIZE = 100

all: 
	make int   SIZE=${SIZE} CFLAGS="-O0 -Wall"
	make int   SIZE=${SIZE} CFLAGS="-O3 -Wall"
	make float SIZE=${SIZE} CFLAGS="-O0 -Wall"
	make float SIZE=${SIZE} CFLAGS="-O3 -Wall"


int:
	gcc ${CFLAGS} -g -o MatrixMultiply MatrixMultiply.c -DNLINE=${SIZE} -DNCOL=${SIZE} -DTYPEELT=int
	time ./MatrixMultiply
float:
	gcc ${CFLAGS} -g -o MatrixMultiply MatrixMultiply.c -DNLINE=${SIZE} -DNCOL=${SIZE} -DTYPEELT=float
	time ./MatrixMultiply
clean:
	rm MatrixMultiply
	cleantex -a main.tex
