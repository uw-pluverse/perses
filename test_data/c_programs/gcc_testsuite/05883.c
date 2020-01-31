


int
foo(signed char *p, int n)
{
  int s = 0;
  int i;

  for (i = 0; i < n; i++) {
    if (p[i] >= 0)
      s++;
    else
      s--;
  }

  return s;
}
