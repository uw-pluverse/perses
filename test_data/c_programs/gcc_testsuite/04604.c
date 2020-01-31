




struct S
{
  int a;
  char p[1];
};

struct S b;

struct S *
foo ()
{
  struct S *i = &b;
  return i + 1;
}

int
main (void)
{
  struct S *i = foo () - 1;
  i->a = 1;
}
