all: eustags

eustags:
	gcc -o eustags eustags.c
	mv -f eustags /usr/local/bin

sockstd:
	cc -o sockstd sockstd.c -lsocket -lnsl

clean:
	rm -f *~ eustags sockstd *.exe

