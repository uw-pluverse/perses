


extern void foo (int);

void
f (int *p, unsigned int n)
{
  foo (*(p + n * 4));
  foo (*(p + 32 + n * 4));
  if (n > 3)
    foo (*(p + 16 + n * 4));
  else
    foo (*(p + 48 + n * 4));
}
