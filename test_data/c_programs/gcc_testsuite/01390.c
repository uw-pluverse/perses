





int foo1 (int c);
int foo2 (int c);

int test (int c)
{
  return (foo1 (c) || foo2 (c));
}
