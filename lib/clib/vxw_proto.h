enum argument_type {
	A_CHAR, A_SHORT, A_LONG, A_FLOAT, A_DOUBLE,
	A_SYMBOL, A_VECTOR, A_STRUCT, A_END};

typedef 
  union number_union {
    double dval;
    struct {float  fval1,fval2;} f;
    struct {long   ival1,ival2;} i;
    struct {short  sval1, sval2, sval3, sval4;} s;
    } number_union;

