


void foo (int);

int
f (int i)
{
  int x, y;

  x = i * 4;
  y = x * 10;
  foo (y);

  i = i + 5;
  x = i * 4;
  y = x * 10;
  foo (y);

  i = i - 4;
  x = i * 4;
  y = x * 10;
  foo (y);
}
