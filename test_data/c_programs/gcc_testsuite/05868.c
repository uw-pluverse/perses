void foo (int *p)
{
  int i;

  for (i = 0; i < 100; i++)
    {
      p[i] = i;
      p[i + 1] = i;
    }
}
