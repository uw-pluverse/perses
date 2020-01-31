






void link_error (void);

void
foo (int *p, int q)
{
  if (p == 0)
    {
      if (q == 0)
 {
   int *r = &p[q];
   if (r != 0)
     link_error ();
 }
    }
}
