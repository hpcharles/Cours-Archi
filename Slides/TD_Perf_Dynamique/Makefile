NATIVECC = gcc
RISCVCC = riscv64-unknown-elf-gcc
ARMCC = aarch64-linux-gnu-gcc-6

CFLAGS = -DTYPEELT=float -DNLINE=1000 -DNCOL=1000 

all:
	echo "make arm|x86|x86-optimize|arm-optimize"

x86:
	make CC=${NATIVECC} OPT="-O0  -masm=intel" asm

arm:
	make CC=${ARMCC} OPT="-O0" asm

x86-optimize:
	make CC=${NATIVECC} OPT="-O3  -masm=intel" asm

arm-optimize:
	make CC=${ARMCC} OPT="-O3" asm

asm:
	${CC}     -S MatrixKernel.c ${CFLAGS} ${OPT} 
