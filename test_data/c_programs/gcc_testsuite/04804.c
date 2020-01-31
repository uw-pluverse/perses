



void
foo (char *p)
{
  volatile int two = 2;
  __builtin_memcpy (p, "abc", two);


  p[0] = 'd';
}
