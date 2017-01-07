
all : test

MARCH=$(shell uname -m)

test_foreign.so : test_foreign.c
ifeq ($(ARCHDIR), Linux64)
##
	gcc -O2 -g -falign-functions=8 -Dx86_64 -DLinux -fPIC -c $<
	gcc -shared -fPIC -falign-functions=8 -o $@ test_foreign.o
else
ifeq ($(ARCHDIR), LinuxARM)
ifeq ($(MARCH), aarch64)
## arm 64bit
	gcc -O2 -g -Wimplicit -falign-functions=8 -Daarch64 -Darmv8 -DARM -DLinux -fPIC -c $<
	gcc -shared -fPIC -falign-functions=8 -o $@ test_foreign.o
else
## arm 32bit
	gcc -O2 -g -falign-functions=4 -DARM -DLinux -fpic -c $<
	gcc -shared -fpic -falign-functions=4 -o $@ test_foreign.o
endif
else
## Linux32 bit
	gcc -m32 -O2 -g -falign-functions=4 -Di386 -Di486 -DLinux -fpic -c $<
	gcc -m32 -shared -fpic -falign-functions=4 -o $@ test_foreign.o
endif
endif

test: test_foreign.so
	irteusgl eus64-test.l

clean :
	\rm -f *.o *.so

