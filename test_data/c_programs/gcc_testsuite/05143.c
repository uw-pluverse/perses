


extern double cos (double);
extern double tan (double);

int
f1 (double x, double y)
{
  double z1 = cos(y<10 ? x : tan(x<20 ? x : y));
  double z2 = cos(y<10 ? x : tan(x<20 ? x : y));
  return z1 == z2;
}
