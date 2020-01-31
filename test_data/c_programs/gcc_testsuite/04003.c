

void
foo (char *p)
{
  long unsigned int s = ~(long unsigned int)0;
  *p = 0;
  __builtin_memset (p + 1, 0, s);
}
