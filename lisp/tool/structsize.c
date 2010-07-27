struct {
  short s;
  long  l;} a;

main()
{ int s;
  s=sizeof(a);
  printf("sizeof(struct short + long)= %d\n",s);
  if (s==6) printf("type Sun3\n");
  else printf("type Sun4\n");}


