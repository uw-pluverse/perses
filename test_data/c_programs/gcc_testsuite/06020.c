




int a, b, c, d, e, f, g;

int
fn1 ()
{
  int *h = &c;
  for (; c < 1; c++)
    {
      int *i = &a, *k = &a;
      f = 0;
      if (b)
 return 0;
      if (*h)
 {
   int **j = &i;
   *j = 0;
   d = 0;
 }
      else
 g = e = 0;
      if (*h)
 {
   int **l = &k;
   *l = &g;
 }
      d &= *h;
      if (!(k == &a || k)) __builtin_abort ();
      if (!(i)) __builtin_abort ();
    }
  return 0;
}

int
main ()
{
  fn1 ();
  return 0;
}
