





extern void exit (int);

double dbl_test (double a, double b, double c, double d)
{
  return (a > b) ? c : d;
}

double dbl_a = 1, dbl_b = 2, dbl_c = 3, dbl_d = 4, dbl_e;

int main()
{
  dbl_e = dbl_test (dbl_a, dbl_b, dbl_c, dbl_d);
  exit (0);
}
