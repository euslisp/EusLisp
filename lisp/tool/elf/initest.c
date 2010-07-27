#include <stdio.h>

#pragma init (foo)
#pragma  fini (bar)

foo()
{ printf("foo is called\n");}

bar()
{ printf("bar is called\n");}

main()
{
printf("main is executing.\n");
}
