#include <stdio.h>
#define ABS(x,y) (((x) > (y))? x - y : y - x)

main(ac, av)
int ac;
char **av;
{
  int tmp, min = 1000000, lineno = 0, minline = 0, minmax = 1000000;
  char s[BUFSIZ];

  if(ac < 3) {
    printf("0\n");
    exit();
  }
  if(ac == 3) minmax = atoi(av[2]);
  while(gets(s) != NULL) {
    lineno++;
    tmp = hamming(s, av[1]);
    if(min > tmp) {
      min = tmp;
      minline = lineno;
    }
  }
  if(minmax > min) 
    printf("%d\n", minline);
  else
    printf("0\n");
}
    

hamming(s1, s2)
char *s1, *s2;
{
  int i, j;
  for(i = j = 0; i < 26; i++) {
    j += ABS(s1[i], s2[i]);
  }
  return j;
}
    
    
