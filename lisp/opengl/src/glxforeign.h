static pointer (*ftab[1])();

#define QUOTE_STRINGS_SIZE 7
static char *quote_strings[QUOTE_STRINGS_SIZE]={
    ":glxforeign",
    "provide",
    "\"GL\"",
    "\"GL\"",
    "*package*",
    "\"no such package\"",
    "(glxchoosevisual glxcopycontext glxcreatecontext glxcreateglxpixmap glxdestroycontext glxdestroyglxpixmap glxgetconfig glxgetcurrentcontext glxgetcurrentdrawable glxisdirect glxmakecurrent glxqueryextension glxqueryversion glxswapbuffers glxusexfont glxwaitgl glxwaitx)",
  };
