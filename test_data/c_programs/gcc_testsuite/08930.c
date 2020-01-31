



void link_error (void);

int f(double a, double b)
{
  if (((a*a) + (b*b))<0)
    link_error();
}
