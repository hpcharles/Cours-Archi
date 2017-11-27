CC = gcc
CC = riscv64-unknown-elf-gcc

CFLAGS = -DTYPEELT=float -DNLINE=1000 -DNCOL=1000 # -masm=intel

all:
	${CC}     -S MatrixKernel.c ${CFLAGS} 
	${CC} -O3 -S MatrixKernel.c ${CFLAGS} 
