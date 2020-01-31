int
foo (int a)
{
  int b = a != 0;
  if (b)
    if (a != 0)
      return 1;
  return 0;
}
