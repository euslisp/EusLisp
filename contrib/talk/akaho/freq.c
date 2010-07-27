#include <stdio.h>
#include <ctype.h>

char a[26];

main()
{
  int i, c;

  for(i = 0; i < 26; i++) a[i] = 0;
  while ((c = getchar()) != EOF) {
    i = tolower(c) - 'a';
    if(i >= 0 && i < 26) a[i] += 1;
    a[i] %= 10;
  }
  for(i = 0; i < 26; i++) putchar(a[i]+'0');
  putchar('\n');
}
