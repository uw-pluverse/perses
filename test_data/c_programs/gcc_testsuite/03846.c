
f(a)
     char *a;
{
  int d = strcmp(a,"-");

  while (vfork() < 0)
    ;
  return d;
}
