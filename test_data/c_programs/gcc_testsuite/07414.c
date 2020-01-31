


float x[256];

void foo(void)
{
  int i;
  for (i=0; i<256; ++i)
    x[i] = x[i] * x[i];
}
