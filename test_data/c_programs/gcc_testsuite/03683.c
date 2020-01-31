

int
foo (int x)
{
  void *p = x ? (void *) 1 : (void *) 0;
  long int b = (long int) p;
  if (b)
    return 0;
  return 1;
}
