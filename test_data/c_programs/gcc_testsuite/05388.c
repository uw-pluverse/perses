




char buf[4], *q;
int foo (int i)
{
  char c, *p;
  q = &c;
  p = buf;
  if (i)
    p = p + 3;
  else
    p = p + 2;
  *p = 6;
  c = 8;
  return *p;
}
