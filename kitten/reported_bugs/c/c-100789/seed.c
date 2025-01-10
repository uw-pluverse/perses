



int x;

int foo(void)
{
  return __transaction_atomic (x + 1);
}

int bar(void)
{
  return __transaction_relaxed (x + 1);
}
