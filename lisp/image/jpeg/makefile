# jpeg compression/decompression for euslisp
# copyright (c) 1997, Toshihiro Matsui, Electrotechnical Laboratory

OS = $(shell /bin/uname | sed s/-.*//)
ifeq ($(OS), Linux)
 LSFX = so
else
 LSFX = dll
endif

$(EUSDIR)/$(ARCHDIR)/lib/jpegmemcd.$(LSFX):	jpegmemcd.o jmemsrc.o jmemdst.o
	gcc -shared -o jpegmemcd.$(LSFX) jpegmemcd.o jmemsrc.o jmemdst.o -ljpeg
	cp jpegmemcd.$(LSFX) $(EUSDIR)/$(ARCHDIR)/lib
jpegmemcd.o:	jpegmemcd.c
	gcc -c -O  jpegmemcd.c $(CFLAGS)
jmemsrc.o:	jmemsrc.c
	gcc -c -O  jmemsrc.c $(CFLAGS)
jmemdst.o:	jmemdst.c
	gcc -c -O  jmemdst.c $(CFLAGS)


