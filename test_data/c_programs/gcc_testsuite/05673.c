


extern void abort (void);
extern void exit (int);

int sum (int n)
{
  if (n == 0)
    return 0;

  return n + sum (n - 1);
}

int fac (int n)
{
  if (n == 0)
    return 1;

  return n * fac (n - 1);
}

int sq_sum (int n)
{
  if (n == 0)
    return 0;

  return n * n + sq_sum (n - 1);
}

int pow2m1 (int n)
{
  if (n == 0)
    return 0;

  return 2 * pow2m1 (n - 1) + 1;
}

int fib (int n)
{
  if (n <= 1)
    return 1;

  return fib (n - 2) + fib (n - 1);
}

int main(void)
{
  if (sum (5) != 15)
    abort ();

  if (fac (5) != 120)
    abort ();

  if (sq_sum (5) != 55)
    abort ();

  if (pow2m1 (5) != 31)
    abort ();

  if (fib (5) != 8)
    abort ();

  exit (0);
}
