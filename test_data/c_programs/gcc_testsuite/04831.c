

extern void f (int *);

void
g (int i)
{
  switch (i)
    {
      int a[3];
      __builtin_memset (a, 0, sizeof a);

    default:
      f (a);
    }

  switch (i)
    {
      int a[3];
      int b[3];
      int c[3];
      b[1] = 60;

    default:
      f (a);
      f (b);
      f (c);
    }
}
