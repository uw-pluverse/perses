


int a, b, c;
void bar (void);
void baz (void);

void
f1 (void)
{
  int i, j;

  if (a)
 for (i = 0; i < 10; i++)
      if (b)
 bar ();
      else
 baz ();

  if (a)
    while (1)
 for (i = 0; i < 10; i++)
 if (b)
   bar ();
 else
   baz ();

  if (a)
    for (i = 0; i < 10; i++)
 for (j = 0; j < 10; j++)
 if (b)
   bar ();
  else
    baz ();

  if (a)
 for (i = 0; i < 10; i++)
      if (b)
 for (j = 0; j < 10; j++)
   if (c)
     bar ();
      else
 baz ();

  if (a)
 for (i = 0; i < 10; i++)
      if (b)
 for (j = 0; j < 10; j++)
   if (c)
     bar ();
   else
     baz ();
  else
    bar ();

  if (a)
 for (i = 0; i < 10; i++)
      if (b)
 bar ();
      else
 baz ();

  if (a)
 for (i = 0; i < 10; i++)
      for (j = 0; j < 10; j++)
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
    for (i = 0; i < 10; i++)
 for (j = 0; j < 10; j++)
 if (b)
   bar ();
  else
    baz ();

  if (a)
 for (i = 0; i < 10; i++)
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
 bar ();
      else
 baz ();

  if (a)
    for (i = 0; i < 10; i++)
 for (j = 0; j < 10; j++)
 if (b)
   bar ();
  else
    baz ();

  if (a)
    for (i = 0; i < 10; i++)
 for (j = 0; j < 10; j++)
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
 bar ();
      else
 baz ();

  if (a)
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
    {
 for (i = 0; i < 10; ++i)
 if (b)
   bar ();
    }
  else baz ();

  if (a)
 for (i = 0; i < 10; i++)
      {
 for (j = 0; j < 10; j++)
   if (b)
     bar ();
   else
     baz ();
      }

  if (a)
 {
 if (b)
   bar ();
 else
   baz ();
      }

  if (a)
    for (i = 0; i < 10; i++)
 for (j = 0; j < 10; j++)
 {
   if (b)
     bar ();
 }
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
 else
   baz ();
      }

  if (a)
    {
 if (b)
   bar ();
 else
   baz ();
    }

  if (a)
    for (i = 0; i < 10; i++)
 for (j = 0; j < 10; j++)
 {
   if (b)
     bar ();
 }
  else
    baz ();

  if (a)
    for (i = 0; i < 10; i++)
 for (j = 0; j < 10; j++)
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
      }
  else
    baz ();

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
 for (i = 0; i < 10; i++)
      {
 if (b)
   bar ();
 else
   baz ();
      }
}

void
f2 (int d, int e, int f)
{
  if (a)
 if (b)
 bar ();
      else
 baz ();

  if (d)
 if (b)
 bar ();
      else
 baz ();

  if (e)
 {
 if (b)
   bar ();
 else
   baz ();
      }

  if (f)
 {
 if (b)
   bar ();
 else
   baz ();
      }
}
