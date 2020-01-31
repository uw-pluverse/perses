


int
__attribute__((optimize("Os"), noinline, noclone))
foo(int a)
{
  return a * a;
}

__attribute__ ((noinline, noclone))
int bar(int b)
{
  return b * b;
}

int main()
{
  return foo (0) + bar (0);
}
