extern void link_error(void);

extern double exp(double);
extern double atan(double);

int main()
{
  if (exp (1.0) < 2.71 || exp (1.0) > 2.72)
    link_error ();
  if (exp (2.0) < 7.38 || exp (2.0) > 7.39)
    link_error ();
  if (exp (-2.0) < 0.13 || exp (-2.0) > 0.14)
    link_error ();
  if (atan (1.0) < 0.78 || atan (1.0) > 0.79)
    link_error ();

  return 0;
}
