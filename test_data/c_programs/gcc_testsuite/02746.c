extern void abort ();

int
main ()
{
  int i;
  double oldrho;
  double beta = 0.0;
  double work = 1.0;
  for (i = 1; i <= 2; i++)
    {
      double rho = work * work;
      if (i != 1)
        beta = rho / oldrho;
      if (beta == 1.0)
        abort ();





      work /= 2.0;
      oldrho = rho;
    }
  return 0;
}
