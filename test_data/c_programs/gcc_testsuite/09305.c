



void bar (void);

void
foo (float *f)
{
  int i;
  for (i = 0; i < 4; i++)
    f[i] = i;
  bar ();
  for (i = 0; i < 4; i++)
    if (f[i] != i)
      __builtin_abort ();
}
