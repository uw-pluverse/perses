void
foo (long int x, long int y)
{
  int i;
  void **a = (void *) (8UL * (x / 8UL));
  for (i = 0; i < x; i++)
    a[i] = (void *) y;
}
