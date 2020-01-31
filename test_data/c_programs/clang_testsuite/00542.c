struct S {
  double a;
  long double b;
};
long double test (struct S x)
{
  return x.b;
}
