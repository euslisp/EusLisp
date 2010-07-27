#define intval(p) (((int)(p))>>2)
#define makeint(v) ((((int)v)<<2)+2)

main()
{

  int x,y,z;
  x=0xe2345678;
  y=makeint(x);
  z=intval(y);

  printf("%x %x %x\n", x,y,z);
  }



