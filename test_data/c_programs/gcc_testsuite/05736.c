




int test (int a, int b, int c)
{
  if (a == 10 || a == 12)
    return b;
  else
    return c;
}
int main ()
{
  if (test (10, 20, 30) != 20)
    __builtin_abort ();
  if (test (12, 20, 30) != 20)
    __builtin_abort ();
  if (test (26, 20, 30) != 30)
    __builtin_abort ();
  return 0;
}
