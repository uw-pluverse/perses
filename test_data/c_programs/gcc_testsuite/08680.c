


__attribute__ ((noinline))
int foo(int x)
{
  int c = x;

  if (x > 10)
    c += 2;
  else
    c -= 3;

  return x;
}

__attribute__ ((noinline))
int bar(int y)
{
  int d = y;

  if (y > 10)
    d += 2;
  else
    d -= 3;

  return d;
}

int main()
{
  return 0;
}
