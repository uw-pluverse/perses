





void bar (long *x, long *y);

void foo (int x, long *y, long *z)
{
  int i;

  for (i = x - 1; i >= 0; i--)
    {
      bar (z + i * 3 + 1, y);
      bar (z + i * 3 + 2, y);
    }
}
