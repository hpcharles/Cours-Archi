
slides:
	pdflatex main
	pdflatex main

SIZE = 100

all: 
	make int   SIZE=${SIZE}   CFLAGS="-O0 -Wall"
	make int   SIZE=${SIZE}   CFLAGS="-O3 -Wall"
	make float SIZE=${SIZE} CFLAGS="-O0 -Wall"
	make float SIZE=${SIZE} CFLAGS="-O3 -Wall"


int:
	gcc ${CFLAGS} -g -o MatrixMultiply MatrixMultiply.c -DNLINE=${SIZE} -DNCOL=${SIZE} 
	time ./MatrixMultiply
float:
	gcc ${CFLAGS} -g -o MatrixMultiply MatrixMultiply.c -DNLINE=${SIZE} -DNCOL=${SIZE} -DTYPEELTFLT
	time ./MatrixMultiply
clean:
	rm MatrixMultiply
