



int *
foo (int *x)
{
  int *a = x + 10, *b = x, *c = a;
  while (b != c)
    *--c = *b++;
  return x;
}
