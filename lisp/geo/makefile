CFLAGS=-D$(MACHINE) -DSolaris2 -K pic -w -I../c
LDFLAGS=-dy -G
OFLAGS=-O
GEOOBJECTS= intersection.o \
	    geoclasses.o \
	    geopack.o geobody.o primt.o compose.o hid.o \
	    viewing.o viewport.o viewsurface.o

libeusgeo.so:	$(GEOOBJECTS)
	cc  $(LDFLAGS) -o libeusgeo.so $(GEOOBJECTS)
	mv libeusgeo.so ../lib
.SUFFIXES:

.c.o:
	cc -c $(CFLAGS) $*.c

