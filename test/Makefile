GCC_MACHINE=$(shell gcc -dumpmachine)
$(info "-- GCC_MACHINE = ${GCC_MACHINE}")
OS=$(shell uname -s | sed 's/[^A-Za-z1-9].*//')
$(info "--      OS = ${OS}")
ifeq ($(OS),Linux)
 export MAKEFILE=Makefile.Linux
endif
ifeq ($(OS),CYGWIN)
 export MAKEFILE=Makefile.Cygwin
endif
ifeq ($(OS),Darwin)
 export MAKEFILE=Makefile.Darwin
endif

$(info "-- MAKEFILE = ${MAKEFILE}")

# set EUSDIR if not defined
export EUSDIR?=$(CURDIR)/..
$(info "--  EUSDIR = ${EUSDIR}")

include $(MAKEFILE)

SRC=testdefforeign.c
OBJ=$(basename $(SRC)).o
LIB=$(LPFX)$(basename $(SRC)).$(LSFX)

$(LIB): $(OBJ)
	$(LD) $(SOFLAGS) $(OUTOPT)$(LIB) $(OBJ) $(LDFLAGS)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -DCOMPILE_LIB -c $(SRC) $(OBJOPT)$(OBJ)

clean:
	rm -f $(LIB) $(OBJ)
