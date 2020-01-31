



int foo (void *x)
{
  int (*fn) (int);
  *(void **)&fn = x;
  return fn (6);
}
