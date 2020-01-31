



int a, c;
int *volatile b;

void
foo (int p)
{
  int d;
  int *e = &a;
  d = ((p == 0) & *e) != 0;
  b = e;
  for (; c;)
    ;
}

void
bar (void)
{
  foo (1);
}
