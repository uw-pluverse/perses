


int g;
int bar();
int blah(int);
void t(int);

static int
__attribute__((always_inline))
foo (int n, int* v, int r)
{
  int flag = 0;
  if (r > n)
    {
      *v = bar();
      flag = 1;
    }

  if (n > g)
    g++;
  else
    bar();

  return flag;
}

int a[100];
int b[100];
int blah(int n)
{
  int i;
   for (i = 0 ; i < n; i++)
     {
       int v;
       if (!foo (n, &v, b[i]))
         return 0;
       t (v);
     }
   return 1;
}
