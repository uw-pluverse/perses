void abort(void);

static inline void
foo (signed char a)
{
  int b = a - 0x7F;
  if (b > 1)
    abort();
}

int main()
{
  unsigned char b;
  for(b = 0; b < 0xFF; b++)
    foo (b);

  return 0;
}
