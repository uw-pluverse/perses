void f (int *p, int **q)
{
  int i;
  for (i = 0; i < 40; i++)
    {
      *q++ = &p[i];
    }
}

int main ()
{
  void *p;
  int *q[40];
  long unsigned int start;


  if (sizeof(start) == sizeof(int))
    start = (long unsigned int) 2147483647;
  else if (sizeof(start) == sizeof(long))
    start = (long unsigned int) 9223372036854775807L;
  else if (sizeof(start) == sizeof(long long))
    start = (long unsigned int) 9223372036854775807LL;
  else
    return 0;


  start &= -32;


  p = (void *)start;


  q[39] = 0;
  f (p, q);
  if (q[39] != (int *)p + 39)
    abort ();

  return 0;
}
