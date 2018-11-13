/*
/* gccls.c
/*
/*	% gccls lisp-file
/*	Generate-C-Converted-Lisp-Source
/*	convert a lisp source code into C which is interpretedly
/*	executed by Euslisp when it is compiled (by cc) and linked.
/*	Though some lisp source programs, e.g. l/constants.l, must be 
/*	loaded during the make procedure, it is hard to locate the
/*	file since no file handling functions are available.
/*	Genlispexec converts "constants.l" into "constants.l.c"
/*	which should be compiled by 'cc'. The resulted "constants.l.o"
/*	may be linked with eus, which then interprets the same program
/*	as defined in "constants.l".
/*
/*	May 1994, (c) Toshihiro Matsui, Electrotechnical Laboratory
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_SIZE 256

static char buf[MAX_LINE_SIZE];

int main(argc,argv)
int argc;
char *argv[];
{
  char *lispfn, cfn[128], hfn[128], tempfn[128], catcom[256], entryname[128];
  FILE *in, *out;
  char *s, *d, ch;
  int i,j,k, string_count;
  
  lispfn=argv[1];
  sprintf(tempfn, "/tmp/%s.c.%d", lispfn, getpid());
  sprintf(cfn, "%s.c", lispfn);
  sprintf(hfn, "/tmp/%s.h.%d", lispfn, getpid());
  in=fopen(lispfn, "r");
  out=fopen(tempfn, "w");

  /* extract basename from lispfn and place it in entryname */
  s=lispfn; d=entryname;
  while (*s != '.' && *s != 0) *d++ = *s++;
  *d = 0;

  fprintf(out, "/* %s: c-converted lisp source of %s */\n", lispfn, cfn);
  fprintf(out, "#include \"eus.h\"\n");
#ifndef alpha
  fprintf(out, "#pragma init (init_object_module)\n");
#endif
#if 0
  fprintf(out, "extern void eval_c_strings();\n");
  fprintf(out, "extern void add_module_initializer();\n");
#endif
  fprintf(out, "extern void %s();\n", entryname);
  fprintf(out, "static void init_object_module()\n");
  fprintf(out, "  {add_module_initializer(\"%s\", (pointer (*)())%s);}\n", entryname, entryname);
  fprintf(out, "const static char *sexp_strings[NUM_LINES]={\n");

  string_count=1;
  
  s=(char *)fgets(buf, MAX_LINE_SIZE, in);
  while (s!=NULL) {
    k=strlen(s);
    fputc('\"', out);
    while (ch= *s++) {
      if (ch=='\n') fputc(' ', out);
      else {
	if (ch=='\"' || ch=='\\') fputc('\\', out);
        fputc(ch, out);}
      }
    fprintf(out, "\",\n");
    s=fgets(buf, MAX_LINE_SIZE, in);
    string_count++;}
  fprintf(out, "\"\" };\n\n");
  fprintf(out, "void %s(ctx)\n", entryname);
  fprintf(out, "context *ctx;\n");
  fprintf(out, "{ eval_c_strings(ctx, NUM_LINES, sexp_strings);}\n");

  fclose(in);
  fclose(out);
  out=fopen(hfn, "w");
  fprintf(out, "#define NUM_LINES %d\n", string_count);
  fclose(out);
  sprintf(catcom, "cat %s %s >%s ", hfn, tempfn, cfn);
  system(catcom);
  unlink(hfn); unlink(tempfn);
  exit(0);
  }

