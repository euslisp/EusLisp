all: eustags

eustags:
	gcc -DGCC3 -w -o eustags eustags.c

sockstd:
	cc -o sockstd sockstd.c -lsocket -lnsl

install:
	mv -f eustags ${EUSDIR}/${ARCHDIR}/bin

clean:
	rm -f *~ eustags sockstd *.exe
