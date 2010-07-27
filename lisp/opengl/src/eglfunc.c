/* $Header: /home/cvs/euslisp/opengl/src/eglfunc.c,v 1.1.1.1 2003/11/20 07:46:32 eus Exp $ */

#include "eus.h"

#include <GL/gl.h>

#pragma init (init_object_module)

pointer EGLGETSTRING(ctx, n, argv)
  register context *ctx;
  int n;
  pointer *argv;
{ 
  char *str;
  integer_t i;
  ckarg(1);
  i = ckintval(argv[0]);
  str = (char *) glGetString(i);
  if (str) 
    return(makestring(str, strlen(str)));
  else 
    return(NIL);
}

eglfunc(ctx, n, argv)
  register context *ctx;
  int n;
  pointer argv[];
{ 
  defun(ctx, "EGLGETSTRING", argv[0], EGLGETSTRING);
}

static init_object_module()
{ 
  add_module_initializer("eglfunc", eglfunc);
}
