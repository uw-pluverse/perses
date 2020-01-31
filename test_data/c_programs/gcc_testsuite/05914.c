


int x;
int a[100];

struct a
{
  int X;
  int Y;
};

struct a arr[100];

void test4(unsigned b)
{
  unsigned i;


  for (i = 0; i < 100; i++)
    {
      arr[b+8].X += i;
      arr[b+9].X += i;
    }
}

void test5(struct a *A, unsigned b)
{
  unsigned i;


  for (i = 0; i < 100; i++)
    {
      A[b].X += i;
      A[b+1].Y += i;
    }
}
