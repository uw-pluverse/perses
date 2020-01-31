


int a, b, c;
void bar (void);
void baz (void);
void f1 (void);

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
      for (j = 0; j < 10; j++)
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
    for (i = 0; i < 10; i++)
 for (j = 0; j < 10; j++)
 {
   if (b)
     bar ();
 }
  else
    baz ();
}

void
f2 (void)
{
  int i, j;

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
 for (i = 0; i < 10; i++)
      if (b)
 for (j = 0; j < 10; j++)
   if (c)
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
 for (i = 0; i < 10; i++)
 for (j = 0; j < 10; j++)
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
 for (i = 0; i < 10; i++)
 {
   if (b)
     bar ();
 }
  else
    baz ();

  if (a)
 for (i = 0; i < 10; i++)
 { {
   for (j = 0; j < 10; j++)
     if (b)
       bar ();
     else
       baz ();
 } }

  if (a)
 for (i = 0; i < 10; i++)
 { {
   for (j = 0; j < 10; j++)
     if (b)
       bar ();
   }
 }
  else
    baz ();
}

void
f3 (void)
{
  int i, j;

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
 for (i = 0; i < 10; i++)
      if (b)
 for (j = 0; j < 10; j++)
   if (c)
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
 else
   baz ();
      }
}

void
f4 (void)
{
  if (a)
 if (b)
 bar ();
      else
 baz ();

  if (a)
 {
 if (b)
   bar ();
 else
   baz ();
      }
}
