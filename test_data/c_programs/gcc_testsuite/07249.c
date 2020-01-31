





void
f (void)
{
  int a[3];
  int (*p)[];
  struct { int (*p)[]; } s;
  p = &a;
  s.p = &a;
}
