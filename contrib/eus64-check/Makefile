
all : test_foreign.so

test_foreign.so : test_foreign.c
ifeq ($(ARCHDIR), Linux64)
	gcc -m64 -O2 -g -falign-functions=8 -Dx86_64 -DLinux -fPIC -c $<
	gcc -m64 -shared -fPIC -falign-functions=8 -o $@ test_foreign.o
else
	gcc -m32 -O2 -g -falign-functions=4 -Di386 -Di486 -DLinux -fpic -c $<
	gcc -m32 -shared -fpic -falign-functions=4 -o $@ test_foreign.o
endif

clean :
	\rm -f *.o *.so
