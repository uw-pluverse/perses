




long long int a;
unsigned long long int b;

void
foo (void)
{
  a = (a < 0) / ((a -= b) ? b >= ((b = a) || 0) : 0);
}
