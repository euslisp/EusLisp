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
ifneq ($(ARCHDIR), Linux64)
CC += -m32
else
CC += -fPIC
endif
endif
ARCH=$(ARCHDIR)
LIBDIR=$(EUSDIR)/$(ARCH)/lib
OBJDIR=$(EUSDIR)/$(ARCH)/obj
OBJFILES= $(OBJDIR)/jpegmemcd.o $(OBJDIR)/jmemsrc.o $(OBJDIR)/jmemdst.o
$(LIBDIR)/jpegmemcd.$(LSFX):	$(OBJFILES)
	$(CC) -shared -o jpegmemcd.$(LSFX) $(OBJDIR)/jpegmemcd.o $(OBJDIR)/jmemsrc.o $(OBJDIR)/jmemdst.o -ljpeg
	mv jpegmemcd.$(LSFX) $(EUSDIR)/$(ARCHDIR)/lib

$(OBJDIR)/jpegmemcd.o:	jpegmemcd.c
	$(CC) -c -o $@ $^
$(OBJDIR)/jmemsrc.o:	jmemsrc.c
	$(CC) -c -o $@ $^
$(OBJDIR)/jmemdst.o:	jmemdst.c
	$(CC) -c -o $@ $^
clean:
	rm -f $(OBJFILES) $(LIBDIR)/jpegmemcd.$(LSFX) eusjpeg.c eusjpeg.h

