



typedef int (*fn) (void);

static inline int
foo (void)
{
  return 1;
}

fn
test (void)
{
  return foo;
}

int
main (void)
{
  fn f = test ();
  return f () != 1;
}
