extern void abort ();

int f(int x)
{
  return (x >> (sizeof (x) * 8 - 1)) ? -1 : 1;
}

volatile int one = 1;
int main (void)
{


  if (f(one) == f(-one))
    abort ();
  return 0;
}
