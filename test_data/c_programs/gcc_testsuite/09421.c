




int
foo (int i, int *a)
{
  int e;
  for (; i; i++)
    e = *a;
  return e;
}
