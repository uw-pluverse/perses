



int foo (char *);

int
bar (unsigned long x)
{
  char a[x];
  return foo (a);
}
