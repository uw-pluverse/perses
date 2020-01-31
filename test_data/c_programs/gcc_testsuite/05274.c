


extern void foo (int);

void
f (int *p, int n)
{
  foo (*(p + n++ * 4));
  foo (*(p + 32 + n++ * 4));
  foo (*(p + 16 + n * 4));
}
