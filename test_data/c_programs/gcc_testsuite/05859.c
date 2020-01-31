

int a[10];
int b[11];
int q (void);
int
t(int n)
{
   int i;
   int sum = 0;
   for (i=0;i<n;i++)
     if (q())
 sum+=a[i];
     else
 sum+=b[i];
  return sum;
}
