extern void __show_tree (int dummy, ...);

extern double sqrt (double x);

void test_quadratic (double a, double b, double c)
{
  __show_tree (0,
     (-b + sqrt (b * b - 4 * a * c))
     / (2 * a));
}
