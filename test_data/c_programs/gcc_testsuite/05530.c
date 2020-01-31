





void
f (int s, char *c, char *x1, char *x2, char *x3)
{
  int a1, a2, a3;

  a1 = 2 * s;
  x1 = c + a1;
  *x1 = 1;
  a2 = 4 * s;
  x2 = c + a2;
  *x2 = 2;
  a3 = 6 * s;
  x3 = c + a3;
  *x3 = 3;
}
