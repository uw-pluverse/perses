





int a[1000000];

void test(int *p)
{
  unsigned i;



  for (i = 0; i < 1000000 - 10000; i++)
    a[i + 10000] = a[i];



  for (i = 0; i < 1000000 - 100000; i++)
    a[i + 100000] = a[i];



  for (i = 0; i < 1000000; i++)
    {
      a[i] = 0;
      *p++ = 1;
    }



  for (i = 0; i < 1000; i++)
    a[i] = 0;
}
