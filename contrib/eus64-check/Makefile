
all : test_foreign.so

test_foreign.so : test_foreign.c
	gcc -m64 -O2 -g -falign-functions=8 -Dx86_64 -DLinux -fPIC -c $<
	gcc -m64 -shared -fPIC -falign-functions=8 -o $@ test_foreign.o

clean :
	\rm -f *.o *.so
