

int i, j, k;
extern int foo (void);

void
f1 (void)
{
 for (i = 0; i < 5; i++)
    ;
  {
    for (j = 0; j < 5; j++)
      ;
  }
}

void
f2 (void)
{
 for (i = 0; i < 5; i++)
    {
      {
 {
   for (j = 0; j < 5; j++)
     {
     }
 }
      }
    }
}

void
f3 (void)
{
 for (i = 0; i < 5; i++)
    {
      int k = foo ();
      {
 {
   for (j = 0; j < 5; j++)
     {
     }
 }
      }
    }
}

void
f4 (void)
{
 for (i = 0; i < 5; i++)
    {
      {
 for (j = 0; j < 5; j++)
   ;
 foo ();
      }
    }
}

void
f5 (void)
{
 for (i = 0; i < 5; i++)
    {
      {
 for (j = 0; j < 5; j++)
   ;
      }
      foo ();
    }
}

void
f6 (void)
{
 for (i = 0; i < 5; i++)
    {
      {
 for (j = 0; j < 5; j++)
   ;
      }
    }
  foo ();
}
