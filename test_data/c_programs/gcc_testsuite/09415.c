






unsigned int a[1000];
unsigned int b[1000];
unsigned int c[1000];

void
f (void)
{
  int i;

    for (i = 0; i < 1000; ++i)
      c[i] = a[i] + b[i];
}
