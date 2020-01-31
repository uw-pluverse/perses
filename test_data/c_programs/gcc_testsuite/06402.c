



void abort (void);
int *a;





int t()
{
   int i;
  for (i=0;i<1000000;i++)
    if (a[i])
      return 1;
  return 0;
}



int t2()
{
   int i;
  for (i=0;i<3000000;i++)
    if (a[i])
        abort ();
  return 0;
}
