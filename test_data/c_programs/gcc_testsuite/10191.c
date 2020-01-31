




int
test_compare (int a, unsigned b)
{
  return (b > 8 * (a ? 4 : 8));
}

unsigned int
test_conditional (int a, unsigned b, int c)
{
  return (c ? b : 8 * (a ? 4 : 8));
}
