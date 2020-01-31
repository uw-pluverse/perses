const int n = 100;

int
private_reduction ()
{
  int i, r;

 for (i = 0; i < 100; i++)
    r += 10;

  return r;
}

int
parallel_reduction ()
{
  int sum = 0;
  int dummy = 0;

 {
 {
      int v = 5;
      sum += 10 + v;
    }
  }

  return sum;
}

int
main ()
{
  int i, s = 0;

 for (i = 0; i < n; i++)
    s += i+1;

 for (i = 0; i < n; i++)
    s += i+1;

  return 0;
}
