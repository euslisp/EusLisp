// for eus.h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <setjmp.h>
#include <errno.h>
#include <sstream>

#define class   eus_class
#define throw   eus_throw
#define export  eus_export
#define vector  eus_vector
#define string  eus_string
#include <eus.h> // include eus.h just for eusfloat_t ...
#undef class
#undef throw
#undef export
#undef vector
#undef string

extern "C" {
  eusfloat_t test1(eusinteger_t v1, eusfloat_t v2) {
    printf("// v1: %d\n", (int)v1);
    printf("// v2: %f\n", v2);
    return v1 + v2;
  }

  eusfloat_t test2(eusfloat_t *v) {
    printf("// v[0]: %f\n", v[0]);
    printf("// v[1]: %f\n", v[1]);
    return v[0] + v[1];
  }
}
