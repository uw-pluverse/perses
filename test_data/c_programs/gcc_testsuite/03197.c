





unsigned ui;
int si;

conv_i1 ()
{




}

conv_i2 ()
{
  ui = (unsigned) 1.7;
  si = (int) 1.7;
}

conv_i3 ()
{

  si = (int) -1.7;
}

conv_1 (d)
     double d;
{
  ui = (unsigned) d;



}

double
foo (u)
     unsigned u;
{
  return u;
}

main ()
{
  printf ("%lf\n", foo (2400000000));

  conv_i1 ();
  printf ("%lf, %u, %d\n", 2400000000.0, ui, si);

  conv_i2 ();
  printf ("%lf, %u, %d\n", 1.7, ui, si);

  conv_i3 ();
  printf ("%lf, %u, %d\n", -1.7, ui, si);

  conv_1 (2400000000.0);
  printf ("%lf, %u, %d\n", 2400000000.0, ui, si);

  conv_1 (1.7);
  printf ("%lf, %u, %d\n", 1.7, ui, si);

  conv_1 (-1.7);
  printf ("%lf, %u, %d\n", -1.7, ui, si);

}
