


extern double fabs (double);
extern float fabsf (float);
extern void abort ();
extern void exit (int);

void
fabd_d (double x, double y, double d)
{
  if ((fabs (x - y) - d) > 0.00001)
    abort ();
}



void
fabd_f (float x, float y, float d)
{
  if ((fabsf (x - y) - d) > 0.00001)
    abort ();
}



int
main ()
{
  fabd_d (10.0, 5.0, 5.0);
  fabd_d (5.0, 10.0, 5.0);
  fabd_f (10.0, 5.0, 5.0);
  fabd_f (5.0, 10.0, 5.0);

  return 0;
}
