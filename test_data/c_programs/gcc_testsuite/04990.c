



int a, b, c;
void bar (void);
void baz (void);

void
f1 (void)
{
  int i;

  if (a)
 for (i = 0; i < 10; i++)
      if (b)
 bar ();
      else
 baz ();

  if (a)
 for (i = 0; i < 10; i++)
      {
 if (b)
   bar ();
 else
   baz ();
      }

  if (a)
 for (i = 0; i < 10; i++)
      {
 if (b)
   bar ();
      }
  else
    baz ();
}
