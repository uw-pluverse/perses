



void
foo(int *a)
{
  (*a)++;
}

int
main ()
{
  int a = 0;
  foo (&a);
  return 0;
}
