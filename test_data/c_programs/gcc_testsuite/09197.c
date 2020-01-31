void foo(volatile int *a, int *b)
{
  *a = 1;
  if (*b)
    *a = 2;
}
