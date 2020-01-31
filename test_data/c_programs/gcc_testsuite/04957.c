


void
foo (void)
{
  long int d;
  const int i = 0;
  int a1[2][0], a2[2][0];
  int b1[3][i], b2[4][i];
  d = a1 - a2;
  __asm volatile ("" : "+g" (d));

  d = b1 - b2;
  __asm volatile ("" : "+g" (d));
}
