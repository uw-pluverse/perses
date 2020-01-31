



void foo (char *pstart, int n)
{
  char *p;
  char *pend = pstart + n;

  for (p = pstart; p < pend; p++)
    *p = 1;
}

void foo1 (char *pstart, int n)
{
  char *p;
  char *pend = pstart + n;

  for (p = pstart; p != pend; p++)
    *p = 1;
}
