# jpeg compression/decompression for euslisp
# copyright (c) 1997, Toshihiro Matsui, Electrotechnical Laboratory

OS = $(shell /bin/uname | sed s/-.*//)
ifeq ($(OS), Linux)
 LSFX = so
else
 LSFX = dll
endif

CC = gcc
ifeq ($(shell /bin/uname -m), x86_64)
CC += -m32
endif

$(EUSDIR)/$(ARCHDIR)/lib/jpegmemcd.$(LSFX):	jpegmemcd.o jmemsrc.o jmemdst.o
	$(CC) -shared -o jpegmemcd.$(LSFX) jpegmemcd.o jmemsrc.o jmemdst.o -ljpeg
	cp jpegmemcd.$(LSFX) $(EUSDIR)/$(ARCHDIR)/lib
jpegmemcd.o:	jpegmemcd.c
	$(CC) -c -O  jpegmemcd.c $(CFLAGS)
jmemsrc.o:	jmemsrc.c
	$(CC) -c -O  jmemsrc.c $(CFLAGS)
jmemdst.o:	jmemdst.c
	$(CC) -c -O  jmemdst.c $(CFLAGS)


