




struct S
{
  int a;
};

int
main ()
{
  struct S s;
  struct S *p = &s;
  return p->a;
}
