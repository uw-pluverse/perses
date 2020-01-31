

unsigned
foo (d)
     double d;
{
  return d;
}
main ()
{
  printf ("%lf\n", (double) ((unsigned) 2410065408));
  foo ((double) 2410065408);
}
