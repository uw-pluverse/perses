

extern void abort (void);

int foo (int x)
{
  return (x / 2) / ((-2147483647 - 1) / -2);
}

int main()
{
  if (foo (- 2147483647 - 1) != -1)
    abort ();
  return 0;
}
