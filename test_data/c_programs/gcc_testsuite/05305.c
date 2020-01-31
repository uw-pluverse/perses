


double cos (double);
void link_error();
void f(double a)
{
  double b = cos (a);
  double c = cos (a);
  if (b != c)
    link_error();
}
