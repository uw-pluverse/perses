


extern volatile float f[];

void foo (void)
{
  int i;
  for (i = 0; i < 100; i++)
    f[i] = 0;
  for (i = 0; i < 100; i++)
    f[i] = 0;
  for (i = 0; i < 100; i++)
    if (f[i])
      __builtin_abort ();
}
