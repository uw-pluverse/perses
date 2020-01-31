


int
main (void)
{
  int a = 1;
  volatile int b = -5;
  long long int c = -6;

  a << -3;
  1 << -4;
  1 << b;
  a << c;
  a << (b + c);

  return 0;
}
