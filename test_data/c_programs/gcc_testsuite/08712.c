


static int __attribute__((noinline))
foo (int *p, int *q)
{
  *p = 2;
  *q = 1;
  return *p;
}

static int __attribute__((noinline))
bar (int *p, int *q)
{
  *p = -2;
  *q = -1;
  return *p;
}

static int __attribute__((noinline,noclone))
foobar (int foo_p)
{
  int a;
  int (*fn)(int *, int *);
  if (foo_p)
    fn = foo;
  else
    fn = bar;
  return (*fn)(&a, &a);
}

extern void abort (void);

int main()
{
  if (foobar (1) != 1)
    abort ();

  return 0;
}
