.SUFFIXES: .c .exe

OS = $(shell /bin/uname | sed s/-.*//)

ifeq ($(OS),Cygwin)
CFLAGS = -I/usr/X11R6/include
LIBDIR = -L/usr/X11R6/lib
GLLIBS = -lX11 -L/usr/X11R6/lib -lgl -lglu -lglut
else
CFLAGS = -I/usr/X11R6/include
LIBDIR = -L/usr/X11R6/lib
GLLIBS = -lX11 -L/usr/X11R6/lib -lGL -lGLU -lglut
endif

all: auxdemo.exe cube.exe scube.exe dinoshade.exe screendoor.exe molehill.exe

.l.c:
	@echo "";

.c.exe:
	gcc -g -o $@ $(CFLAGS) $< $(LIBDIR) $(GLLIBS)

auxdemo.exe: auxdemo.c
cube.exe: cube.c
scube.exe: scube.c
dinoshade.exe: dinoshade.c
screendoor.exe: screendoor.c
molehil.exe: molehil.c

clean:
	rm -f *~ *.exe *.exe.stackdump
	chmod a-x *
