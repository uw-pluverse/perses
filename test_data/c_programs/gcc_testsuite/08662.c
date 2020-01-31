


static int __attribute__((noinline,noclone))
foo (int *p, int *q)
{
  *p = 1;
  *q = 0;
  return *p;
}

extern void abort (void);

int main()
{
  int a, b;
  if (foo (&a, &b) != 1)
    abort ();
  return 0;
}
