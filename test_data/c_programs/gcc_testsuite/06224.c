


void
g (int a, int b, int c, int d)
{
  if (d)
    {
      ((void)
       (!(a && b && c) ? __builtin_unreachable (), 0 : 0));
    }
  ((void)
   (!(a && b && c) ? __builtin_unreachable (), 0 : 0));
}
