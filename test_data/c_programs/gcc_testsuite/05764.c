


struct f { int i; };
int g()
{
  struct f a, *a1;
  int *i;
  a.i = 1;
  a1 = &a;
  i = &a1->i;
  return *i;
}
