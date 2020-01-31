

extern int a[];

void foo (void)
{
  int i;
  for (i = 0; i < 199; i++)
    {
      if (a[i] != i)
 __builtin_abort ();
    }
}
