




struct S { int val[16]; };

static inline int
bar (struct S x)
{
  long double pc = 0;
  int i;
  for (i = 0; i < 16; i++)
    pc += x.val[i];
  return pc;
}

int
foo (struct S x)
{
  return bar (x);
}
