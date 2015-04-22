# jpeg compression/decompression for euslisp
# copyright (c) 1997, Toshihiro Matsui, Electrotechnical Laboratory

OS = $(shell uname | sed s/-.*//)
ifeq ($(OS), Linux)
 LSFX = so
else
ifeq ($(OS), Darwin)
 LSFX = so
else
 LSFX = dll
endif
endif

ifneq ($(OS), Darwin)
 LD = gcc -shared 
else
 LD = gcc -dynamiclib
endif

ifeq ($(shell uname -m), x86_64)
ifneq ($(ARCHDIR), Linux64)
ifneq ($(ARCHDIR), Darwin)
CC += -m32
else
CC += -fPIC
endif
else
CC += -fPIC
endif
endif
ifeq ($(ARCHDIR), Darwin)
CC += -I/opt/local/lib/jpeg6b/include -I/opt/local/include
LD += -L/opt/local/lib/jpeg6b/lib     -L/opt/local/lib
endif
ifeq ($(ARCHDIR), LinuxARM)
CC += -fPIC
endif
ARCH=$(ARCHDIR)
LIBDIR=$(EUSDIR)/$(ARCH)/lib
OBJDIR=$(EUSDIR)/$(ARCH)/obj
OBJFILES= $(OBJDIR)/jpegmemcd.o $(OBJDIR)/jmemsrc.o $(OBJDIR)/jmemdst.o
$(LIBDIR)/jpegmemcd.$(LSFX):	$(OBJFILES)
	$(LD) -o $(LIBDIR)/jpegmemcd.$(LSFX) $(OBJDIR)/jpegmemcd.o $(OBJDIR)/jmemsrc.o $(OBJDIR)/jmemdst.o -ljpeg

$(OBJDIR)/jpegmemcd.o:	jpegmemcd.c
	$(CC) -c -o $@ $^
$(OBJDIR)/jmemsrc.o:	jmemsrc.c
	$(CC) -c -o $@ $^
$(OBJDIR)/jmemdst.o:	jmemdst.c
	$(CC) -c -o $@ $^
clean:
	rm -f $(OBJFILES) $(LIBDIR)/jpegmemcd.$(LSFX) eusjpeg.c eusjpeg.h

