


int a, b, c;
void bar (void);
void baz (void);
void bar2 (void);
void baz2 (void);

void
f1 (void)
{
  int i, d[10] = { 0 };

  if (a)
 if (b)
 bar ();
      else
 baz ();

 if (a)
 if (b)
 bar ();
      else
 baz ();

  if (a)
 if (b)
 bar2 ();
      else
 baz2 ();

  if (a)
 for (i = 0; i < 10; i++)
      if (b)
 bar2 ();
      else
 baz2 ();

  if (a)
 if (b)
 bar2 ();
      else
 baz2 ();

  if (a)
 for (i = 0; i < 10; i++)
      if (b)
 bar2 ();
      else
 baz2 ();

  (void) d[0];

  if (a)
 {
 if (b)
   bar ();
 else
   baz ();
      }

  if (a)
 {
 if (b)
   bar ();
      }
  else
    baz ();

 if (a)
 {
      if (b)
 bar ();
      else
 baz ();
    }

 if (a)
 {
      if (b)
 bar ();
    }
  else
    baz ();

  if (a)
 {
      if (b)
 bar2 ();
      else
 baz2 ();
    }

  if (a)
 for (i = 0; i < 10; i++)
      {
 if (b)
   bar2 ();
 else
   baz2 ();
      }

  if (a)
 {
 if (b)
   bar2 ();
 else
   baz2 ();
      }

  if (a)
 for (i = 0; i < 10; i++)
      {
 if (b)
   bar2 ();
 else
   baz2 ();
      }

  if (a)
    {
 for (i = 0; i < 10; i++)
 if (b)
   bar2 ();
 else
   baz2 ();
    }
}

void
f2 (int *a, int b, int c)
{
  int i;

  if (b)
 for (i = 0; i < 10; i++)
 if (c)
   a[i] = a[i] + 1;
 else
   a[i] = a[i] + 2;

  if (b)
 for (i = 0; i < 10; i++)
 {
   if (c)
     a[i] = a[i] + 1;
   else
     a[i] = a[i] + 2;
 }
}
