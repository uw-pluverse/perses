


__attribute__ ((noinline))
int foo(int a)
{
  return a * a;
}

__attribute__ ((noinline))
int bar(int b)
{
  return b;
}

__attribute__ ((noinline))
void caller(int x)
{
  return;
}

int main(int argc, char **argv)
{
  caller(foo(argc));
  caller(bar(argc));

  return 123;
}
