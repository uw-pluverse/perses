



int
foo (int x)
{
  const int y = 0;
  int r = 0;
  r += x / y;
  r += x / 0;
  r += x % y;
  r += x % 0;
  return r;
}
