



extern void abort (void);

struct X { int a[128]; };
static const struct X a = { 0, 1, 2, 3 };


static const struct X A __attribute__((alias("a")));
struct X *q;
int __attribute__((noinline))
foo ()
{
  struct X b = A;
  int *p = &b.a[2];

  q = &b;
  return *p;
}

int main()
{
  if (foo() != 2)
    abort ();
  return 0;
}
