all: eustags

eustags:
	gcc -o eustags eustags.c
	cp eustags $(EUSDIR)/$(ARCHDIR)/bin

sockstd:
	cc -o sockstd sockstd.c -lsocket -lnsl

clean:
	rm -f *~ eustags sockstd *.exe

