


int foo(int a)
{
  int x;
  x = 0;
  if (a > 0) x = 1;
  if (a < 0) x = 1;
  return x;
}

int main()
{
  if (foo(1) != 1)
    abort();
  return 0;
}
