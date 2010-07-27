static pointer (*ftab[2])();

#define QUOTE_STRINGS_SIZE 10
static char *quote_strings[QUOTE_STRINGS_SIZE]={
    ":eglforeign",
    "provide",
    ":gldecl",
    "\"lisp/opengl/src/gldecl.l\"",
    "require",
    "\"GL\"",
    "\"GL\"",
    "*package*",
    "\"no such package\"",
    "(eglgetstring)",
  };
