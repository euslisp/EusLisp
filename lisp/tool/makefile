all: eustags

eustags:
	gcc -DGCC3 -w -o eustags eustags.c
	sudo mv -f eustags /usr/local/bin

sockstd:
	cc -o sockstd sockstd.c -lsocket -lnsl

clean:
	rm -f *~ eustags sockstd *.exe

