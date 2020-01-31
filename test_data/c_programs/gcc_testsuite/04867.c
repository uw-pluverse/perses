


extern void bark (void);
int i,j,k;
int array[555];

int
main()
{
 for (i=0; i < 100; ++i)
    for (j=0; j < 100; ++j)
      {




 bark ();
      }


 bark();


 for (i=0; i < 100; ++i)
    for (j=0; j < 100; ++j)
      {

 }

 for (i=0; i < 100; ++i)
    for (j=0; j < 100; ++j)
      {
 bark();
      }

 for (i=0; i < 100; ++i)
    for (j=0; j < 100; ++j)
      {
 bark();
      }

 for (i=0; i < 100; ++i)
    for (j=0; j < 100; ++j)
      {
 bark();
      }
}

void bar (int, int, int);

void
foo (int n, int m, int o)
{
  int i, j, k;
 for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
 for (k = 0; k < o; k++)
   {
 bar (i, j, k);
 }
    }
}

int
baz ()
{
  int i, j;
 for (i=0; i < 100; ++i)
    for (j=0; j < 100; ++j)
      {
 bar (i, j, 0);
 }
}
