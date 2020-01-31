







extern void bar (int);

int
foo (int *p, int b)
{
  int a;

  if (b)
    bar (123);
  else
    bar (321);

  a = *p;
  if (p == 0)
    return 0;

  return a;
}
