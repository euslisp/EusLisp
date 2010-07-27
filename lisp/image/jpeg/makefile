# jpeg compression/decompression for euslisp
# copyright (c) 1997, Toshihiro Matsui, Electrotechnical Laboratory

JPEGLIBDIR=/usr/local/jpeg/jpeg-6a
CFLAGS= -Kpic -I$(JPEGLIBDIR)

jpegmemcd.so:	jpegmemcd.o jmemsrc.o jmemdst.o
	cc -o jpegmemcd.so -G  jpegmemcd.o jmemsrc.o jmemdst.o -L$(JPEGLIBDIR) -R$(JPEGLIBDIR) -ljpeg
jpegmemcd.o:	jpegmemcd.c
	cc -c -O  jpegmemcd.c $(CFLAGS)
jmemsrc.o:	jmemsrc.c
	cc -c -O  jmemsrc.c $(CFLAGS)
jmemdst.o:	jmemdst.c
	cc -c -O  jmemdst.c $(CFLAGS)


