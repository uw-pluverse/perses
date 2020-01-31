

int foo (int b, int j)
{
  if (b)
    {
      int i;
      for (i = 0; i<1000; ++i)
        ;
      j = 0;
    }
  return j;
}
