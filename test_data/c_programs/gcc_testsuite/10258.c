extern void link_error(void);

void test(double x)
{
  if (x+x != 2.0*x)
    link_error ();
  if (x+x != x*2.0)
    link_error ();

  if (x+x+x != 3.0*x)
    link_error ();
  if (x+x+x != x*3.0)
    link_error ();

  if ((x+x)+x != 3.0*x)
    link_error ();
  if ((x+x)+x != x*3.0)
    link_error ();

  if (x+(x+x) != 3.0*x)
    link_error ();
  if (x+(x+x) != x*3.0)
    link_error ();

  if (x+4.0*x != 5.0*x)
    link_error ();
  if (x+4.0*x != x*5.0)
    link_error ();
  if (x+x*4.0 != 5.0*x)
    link_error ();
  if (x+x*4.0 != x*5.0)
    link_error ();
  if (4.0*x+x != 5.0*x)
    link_error ();
  if (4.0*x+x != x*5.0)
    link_error ();
  if (x*4.0+x != 5.0*x)
    link_error ();
  if (x*4.0+x != x*5.0)
    link_error ();

  if (3.0*x + 5.0*x != 8.0*x)
    link_error ();
  if (3.0*x + 5.0*x != x*8.0)
    link_error ();
  if (x*3.0 + 5.0*x != 8.0*x)
    link_error ();
  if (x*3.0 + 5.0*x != x*8.0)
    link_error ();
  if (3.0*x + x*5.0 != 8.0*x)
    link_error ();
  if (3.0*x + x*5.0 != x*8.0)
    link_error ();
  if (x*3.0 + x*5.0 != 8.0*x)
    link_error ();
  if (x*3.0 + x*5.0 != x*8.0)
    link_error ();
}

int main()
{
  test(2.0);
  return 0;
}
