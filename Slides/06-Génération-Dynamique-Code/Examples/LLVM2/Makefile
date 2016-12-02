
all: static dynamic

static:
	echo "Static chain"
	clang -o Hello Hello.c
	./Hello 43

dynamic:
	echo "Dynamic chain"
	clang -O3 -emit-llvm -S Hello.c
	clang -O3 -emit-llvm -c Hello.c
	lli Hello.bc 41
