







extern volatile int foo;

int
read_foo (void)
{
  return foo;
}

void
write_foo (int x)
{
  foo = x;
}
