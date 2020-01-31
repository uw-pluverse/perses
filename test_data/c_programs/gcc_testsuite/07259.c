


extern void abort (void);
int __attribute__((noinline, noclone))
bar (void)
{
  return 1;
}

struct S
{
  unsigned long p, q, r;
  void *v;
};

struct S *s1;
struct S *s2;

void __attribute__((noinline, noclone))
fn2 (struct S *x)
{
  s2 = x;
}

__attribute__((noinline, noclone)) void *
fn1 (struct S *x)
{

  s1 = x;

  return (void *)0;
}

int __attribute__((noinline, noclone))
baz (void)
{
  struct S *x = (struct S *) 0x80000000ULL;

  x += bar ();

  fn1 (x);
  fn2 (x);

  return 0;
}

int
main (void)
{
  baz ();

  if (s2 != (((struct S *) 0x80000000ULL) + 1))
    abort ();

  return 0;
}
