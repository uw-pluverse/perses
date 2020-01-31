



void
foo (volatile int *p, int q)
{
  *(volatile int *)p = 0;
  *(p + (q - q) + 1) = 0;
  *(p + (q - q) + 2) = 0;
  *(p + (q - q) + 3) = 0;
}
