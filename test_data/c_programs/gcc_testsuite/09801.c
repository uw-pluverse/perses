



void
f (int *a, int *b)
{
  int i;

  for (i = 0; i < 100; i++)
    {
      int d = 42;

      a[i] = d;
      if (i % 2)
 d = i;
      b[i] = d;
    }
}
