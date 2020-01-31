



void
foo (char *p)
{
  __builtin_memcpy (p, "abc", 2);


  p[0] = 'd';
}
