



struct
{
  int x;
  int y;
  char c;
  int d;
}a;

int foo(int x, int y)
{
  int c;
  a.x = x;
  c = a.x;
  a.d = c;
  a.y = y;

  return 0;
}
