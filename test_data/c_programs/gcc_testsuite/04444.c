int
foo (int i, _Bool b)
{
  int r = 0;

  r += i <= (0 || 1);
  r += i <= b;
  r += i <= 0;
  r += i < (0 || 1);
  r += i < b;
  r += i < 0;
  r += i > (0 || 1);
  r += i > b;
  r += i > 0;
  r += i >= (0 || 1);
  r += i >= b;
  r += i >= 0;

  return r;
}
