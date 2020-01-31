




__attribute__((noinline)) int
foo (int x)
{
  return x;
}

int foo (int x);

int
bar (int x)
{
  return foo (x);
}
