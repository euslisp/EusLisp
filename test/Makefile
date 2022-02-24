GCC_MACHINE=$(shell gcc -dumpmachine)
$(info "-- GCC_MACHINE = ${GCC_MACHINE}")
ifeq ($(shell echo $(GCC_MACHINE) | sed 's/.*-\(.*\)-.*/\1/'), linux)
  OS=Linux
else ifeq ($(shell echo $(GCC_MACHINE) | sed 's/.*-.*-\([a-zA-Z]*\).*/\1/'), darwin)
  OS=Darwin
else ifeq ($(shell echo $(GCC_MACHINE) | sed 's/.*-.*-\(.*\)/\1/'), cygwin)
  OS=Cygwin
endif
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

SRC=test_foreign.c
OBJ=$(basename $(SRC)).o
LIB=$(basename $(SRC)).$(LSFX)

$(LIB): $(OBJ)
	$(LD) $(SOFLAGS) $(OUTOPT)$(LIB) $(OBJ) $(LDFLAGS)
	@echo "Try make test"

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -DCOMPILE_LIB -c $(SRC) $(OBJOPT)$(OBJ)

clean:
	rm -f $(LIB) $(OBJ)

test: $(LIB)
	teusgl eus64-test.l

clean :
	\rm -f *.o *.so

