int test1()
{
  int i, j, k, b[10];
  int a[30];
  double d;
  float r;
  i = 0;
 while(1)
    {
      if (i > 0) break;
      i = i + 1;
    }
  i = 0;
 for(;;)
    {
      if (i > 0) break;
      i = i + 1;
    }
  i = 0;
 do
    {
      i = i + 1;
    }
  while (i < 4);
 while (i < 8)
    {
      i = i + 1;
    }
 for (d = 1; d < 30; d+= 6)
    {
      i = d;
      a[i] = 1;
    }
 for (i = 1; i < 30; i++ )
    if (i == 16) break;


 for (i = 1; i < 10; i++)
    {
    }
 for (i = 1; i < 10; i+=2)
    {
      a[i] = i;
    }


 a[1] = 1;
    for (i = 1; i < 10; i++)
      ;

 for(i = 1; i < 10; i++)
    {
    }
 for(i = 1; i < 10; i++)
    {
    }
  return 0;
}


void PR64765(float *f, double *r) {
  int i;
 for(i = 64; i < 76; i += 5) {}
}
