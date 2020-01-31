



extern int isnan (double __value) __attribute__ ((__const__));

int gsl_isnan (const double x)
{
  return isnan(x);
}
