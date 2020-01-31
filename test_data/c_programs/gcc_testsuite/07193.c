



int sum(int *buf, int len)
{
  int s = 0;
  while (--len > 0) s += *buf++;
  return s;
}
