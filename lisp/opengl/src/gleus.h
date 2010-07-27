static pointer (*ftab[5])();

#define QUOTE_STRINGS_SIZE 14
static char *quote_strings[QUOTE_STRINGS_SIZE]={
    "symbol-string",
    "\"(~a) \"",
    "eglgetstring",
    "read-from-string",
    "member",
    ":gleus",
    "provide",
    "\"GL\"",
    "\"GL\"",
    "*package*",
    "\"no such package\"",
    "(probe-extension)",
    "probe-extension",
    "\"(ext)\"",
  };
