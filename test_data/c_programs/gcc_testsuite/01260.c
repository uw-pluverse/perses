




int
foo (int a, int b)
{
  if (a != b)
    {
      a = a << b;
      a = a >> 1;
    }

  return a + b;
}
