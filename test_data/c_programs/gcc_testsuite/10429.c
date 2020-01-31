



void f(long unsigned int d)
{
  typedef int t[d];
  t *g = (__typeof (g)) d;
  (void) g;
}
