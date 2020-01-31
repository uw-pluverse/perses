







extern void abort (void);

struct bar { int count; int *arr;};

void foo (struct bar *b)
{
  b->count = 0;
  *(b->arr) = 2;
  if (b->count == 0)
    abort ();
}

int
main ()
{
  struct bar x;
  x.arr = &x.count;
  foo (&x);
  return 0;
}
