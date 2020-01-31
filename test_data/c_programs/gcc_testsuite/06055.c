






int foo (int *p)
{
  int i = 0, *x;

  for (x = p; x < p + 2; x++)
    i++;

  return i;
}
