


extern void abort (void);

int f(int a, int b)
{
  if (a > 2147483647 - 15) return 0;
  if (b > 2147483647 - 15) return 0;

  int c = (a - 20) + (b - 20);
  return c > 2147483647 - 15;
}

int main()
{
  if (f (2147483647 - 15, 41) != 1)
    abort ();
  return 0;
}
