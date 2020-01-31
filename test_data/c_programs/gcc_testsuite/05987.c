


int x;
int a[100];

struct a
{
  int X;
  int Y;
};

void bla(void);

void test1(void)
{
  unsigned i;


  for (x = 0; x < 100; x++)
    a[x] = x;
}

void test2(void)
{
  unsigned i;


  for (x = 0; x < 100; x++)
    bla ();
}

void test3(struct a *A)
{
  unsigned i;


  for (i = 0; i < 100; i++)
    {
      A[5].X += i;
      A[5].Y += i;
    }
}
