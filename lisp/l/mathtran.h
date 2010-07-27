static pointer FLET66510();
static pointer FLET66512();
static pointer FLET66514();
static pointer FLET66516();
static pointer FLET66518();
static pointer FLET66520();
static pointer FLET66522();
static pointer FLET66524();
static pointer (*ftab[6])();

#define QUOTE_STRINGS_SIZE 41
static char *quote_strings[QUOTE_STRINGS_SIZE]={
    "\"illegal expression in % macro\"",
    ":test",
    "equal",
    "assoc",
    "\"illegal math expression for % macro\"",
    "values",
    "aref",
    "**",
    "*",
    "temp",
    "let",
    "expt",
    "(* /)",
    "(* /)",
    "(+ -)",
    "-",
    "(+ -)",
    "+",
    "(+ -)",
    "(== != /= < > <= >=)",
    "((== =) (!= /=) (/= /=) (< <) (<= <=) (> >) (>= >=))",
    "let*",
    "=",
    "setq",
    "setf",
    "cdddr",
    "read-delimited-list",
    "\"LISP\"",
    "\"LISP\"",
    "*package*",
    "\"no such package\"",
    "expression",
    "\"(exp &optional (lhs nil) &aux result letvar-alist)\"",
    "infix2prefix",
    "\"(file &optional char)\"",
    "read-aref",
    "\"(file &optional char)\"",
    "set-syntax-from-char",
    ":mathtran",
    "\"@(#)$Id: mathtran.l,v 1.1.1.1 2003/11/20 07:46:31 eus Exp $\"",
    "provide",
  };
