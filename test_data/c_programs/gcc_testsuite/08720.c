


int a, b;

static int __attribute__((noinline,noclone))
foo (int *p, int *q)
{
  int res;
  *p = 1;
  *q = 0;
  res = *p;
  a = 1;
  b = 1;
  return res;
}

extern void abort (void);

int main()
{
  if (foo (&a, &b) != 1)
    abort ();
  return 0;
}
