


int (*fn)(int *);

static int __attribute__((noinline,noclone))
foo (int *p)
{
  return *p;
}

extern void bar (void);

int main()
{
  fn = foo;
  bar ();
  return 0;
}
