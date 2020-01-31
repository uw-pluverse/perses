
const double dnan = 1.0/0.0 - 1.0/0.0;
double x = 1.0;

extern void link_error (void);
extern void abort (void);

main ()
{


  if (dnan == dnan)
    link_error ();
  if (dnan != x)
    x = 1.0;
  else
    link_error ();

  if (dnan < x)
    link_error ();
  if (dnan > x)
    link_error ();
  if (dnan <= x)
    link_error ();
  if (dnan >= x)
    link_error ();
  if (dnan == x)
    link_error ();

  exit (0);
}


void link_error (void)
{
  abort ();
}
