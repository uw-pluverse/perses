




void foo (void);
void bar (void);
void blah (void);



void
baz_1 (int a, int b, int c)
{
  if (a && b)
    foo ();
  if (!b && c)
    bar ();
}



void
baz_2 (int a, int b, int c)
{
  if (a && b)
    foo ();
  if (b || c)
    bar ();
}



void
baz_3 (int a, int b, int c)
{
  if (a && b > 10)
    foo ();
  if (b < 5 && c)
    bar ();
}



void
baz_4 (int a, int b, int c)
{
  if (a && b)
    {
      foo ();
      if (c)
        bar ();
    }
  if (b && c)
    blah ();
}



void
baz_5 (int a, int b, int c)
{
  if (a && b)
    {
      foo ();
      if (c)
        bar ();
    }
  if (!b || !c)
    blah ();
}



void
baz_6 (int a, int b, int c)
{
  if (a == 39 && b == 41)
    foo ();
  if (c == 12 || b == 41)
    bar ();
}
