


int foo(void);
void bla(void);
void bar(void);

void test1 (void)
{
  unsigned i;


  i = 0;
  while (1)
    {
      i++;
      if (i == 100)
 break;

      if (foo ())
 bla ();
      else
 bar ();
    }
}

void test2 (void)
{
  unsigned i, j;


  i = j = 0;
  while (1)
    {
      j++;
      foo ();
      if (j < 100)
 continue;

      i++;
      j = 0;
      if (i == 100)
 break;
    }
}

void test3 (void)
{
  unsigned i, j, k;


  i = j = k = 0;
  while (1)
    {
      j++;
      foo ();
      if (j < 100)
 continue;

      j = 0;
      k++;
      if (k < 100)
 continue;

      k = 0;
      i++;
      if (i == 100)
 break;
    }
}

void test4 (void)
{
  unsigned i, j, k;


  i = j = 0;
  while (1)
    {
      j++;
      foo ();
      for (k = 0; k < 100; k++)
 foo ();

      if (j < 100)
 continue;

      i++;
      j = 0;
      if (i == 100)
 break;
    }
}


void test5 (void)
{
  unsigned i, j;


  i = j = 0;
  while (1)
    {
      j++;
      foo ();
      if (j < 100)
 continue;
      j = 0;

      i++;
      if (i == 100)
 break;

      if (foo ())
 bla ();
      else
 bar ();
    }
}
