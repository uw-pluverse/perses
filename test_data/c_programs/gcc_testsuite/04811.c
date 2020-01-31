



void
foo (char *p)
{
  __builtin_memcpy (p, "abc", 0);


  p[0] = 'd';
}
