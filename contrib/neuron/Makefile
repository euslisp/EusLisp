nnsub.so : nnsub.o
	ld -o nnsub.so nnsub.o

nnsub.o : nnsub.c nnsub.h
	cc -c -Dsun4 -w -DSolaris2 -DTHREADED -fpic -I/opt/eus/include nnsub.c

