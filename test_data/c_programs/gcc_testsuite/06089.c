




extern int g();

double m, n, o;

void f1(double y, double z, double w)
{
  double b, c, d, e, f;

  if (g ())
    b = 1 / y, c = z / y;
  else
    b = 3 / y, c = w / y;

  d = b / y;
  e = c / y;
  f = 1 / y;

  m = d;
  n = e;
  o = f;
}
