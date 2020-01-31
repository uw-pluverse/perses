





struct S { unsigned char s, t[17]; };
int bar (void);

void
foo (struct S *x)
{
  unsigned char i, z;
  if (bar ())
    {
      z = bar ();
      bar ();
      x->s += z;
      for (i = 0; i < x->s; i++)
 x->t[i] = bar ();
    }
}
