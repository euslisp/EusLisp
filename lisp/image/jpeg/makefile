# jpeg compression/decompression for euslisp
# copyright (c) 1997, Toshihiro Matsui, Electrotechnical Laboratory

ifeq ($(shell gcc -dumpmachine | sed 's/.*-\(.*\)-.*/\1/'), linux)
  OS=Linux
else ifeq ($(shell gcc -dumpmachine | sed 's/.*-.*-\([a-zA-Z]*\).*/\1/'), darwin)
  OS=Darwin
else ifeq ($(shell gcc -dumpmachine | sed 's/.*-.*-\(.*\)/\1/'), cygwin)
  OS=Cygwin
endif
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

ifeq ($(shell gcc -dumpmachine | sed 's/\(.*\)-.*-.*/\1/'), x86_64)
ifneq ($(ARCHDIR), Linux64)
ifneq ($(ARCHDIR), Darwin)
CC += -m32
else
CC += -fPIC
endif
else
CC += -fPIC
endif
else
CC += -fPIC
endif
ifeq ($(ARCHDIR), Darwin)
CC += -I/opt/local/lib/jpeg6b/include -I/opt/local/include -I/opt/homebrew/include
LD += -L/opt/local/lib/jpeg6b/lib     -L/opt/local/lib -L/opt/homebrew/lib
endif
ifeq ($(ARCHDIR), LinuxARM)
CC += -fPIC
endif
CC += -fsigned-char
ARCH=$(ARCHDIR)
LIBDIR=$(EUSDIR)/$(ARCH)/lib
OBJDIR=$(EUSDIR)/$(ARCH)/obj
OBJFILES= $(OBJDIR)/jpegmemcd.o $(OBJDIR)/jmemsrc.o $(OBJDIR)/jmemdst.o
$(LIBDIR)/jpegmemcd.$(LSFX):	$(OBJFILES)
	$(LD) -fPIC $(LDFLAGS) -o $(LIBDIR)/jpegmemcd.$(LSFX) $(OBJDIR)/jpegmemcd.o $(OBJDIR)/jmemsrc.o $(OBJDIR)/jmemdst.o -ljpeg

$(OBJDIR)/jpegmemcd.o:	jpegmemcd.c
	$(CC) $(CFLAGS) -c -o $@ $^
$(OBJDIR)/jmemsrc.o:	jmemsrc.c
	$(CC) $(CFLAGS) -c -o $@ $^
$(OBJDIR)/jmemdst.o:	jmemdst.c
	$(CC) $(CFLAGS) -c -o $@ $^
clean:
	rm -f $(OBJFILES) $(LIBDIR)/jpegmemcd.$(LSFX) eusjpeg.c eusjpeg.h

install: $(LIBDIR)/jpegmemcd.$(LSFX)
	install -d $(DESTDIR)/usr/lib/
	install -m 644 $(LIBDIR)/jpegmemcd.$(LSFX) $(DESTDIR)/usr/lib/
