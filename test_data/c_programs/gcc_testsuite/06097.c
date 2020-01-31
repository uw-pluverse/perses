


int *p;
int inline bar(void) { return 0; }
int foo(int x)
{
  int i;
  int *q;
  if (bar())
    q = &i;
  else
    q = p;
  return *q + *p;
}
