



float b[10][15][10];

__attribute__ ((noreturn)) void
noreturn (void)
{
  for (;;);
}

__attribute__ ((noinline, noclone)) void
foo (int n)
{
  int i;

 for (i = 0; i < 10; i++)
    for (int j = n; j < 8; j++)
      for (long k = -10; k < 10; k++)
 {
   b[i][j][k] += 16;
   noreturn ();
   b[i][j][k] -= 32;
 }
}

__attribute__ ((noinline, noclone)) void
bar (void)
{
  int i;

 for (i = 0; i < 10; i++)
    {
      b[0][0][i] += 16;
      noreturn ();
      b[0][0][i] -= 32;
    }
}
