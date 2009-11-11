#include <stdio.h>
#include <time.h>

extern char *tzname[2];
int main(void)
{
  printf("without tzset()\n");
  printf("tzname: [%s][%s]\n", tzname[0], tzname[1]);

  tzset();
  printf("with tzset()\n");
  printf("tzname: [%s][%s]\n", tzname[0], tzname[1]);
  
  return 0;
}
