



void
foo (char *p)
{
  volatile int zero = 0;
  __builtin_memcpy (p, "abc", zero);


  p[0] = 'd';
}
