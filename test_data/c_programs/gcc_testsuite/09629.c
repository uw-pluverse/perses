


extern void baz (int);

void foo (int j, int k)
{
  int i;


#pragma omp for
 for (i = 0; i < 10; i++)
    baz (i);

#pragma omp for
 for (i = j; i <= 10; i+=4)
    baz (i);

#pragma omp for
 for (i = j; i > 0; i = i - 1)
    baz (j);

#pragma omp for
 for (i = j; i >= k; i--)
    baz (i);

#pragma omp for
 for (int l = j; l < 10; l++)
    baz (l);


#pragma omp for
 i = 0;
  for ( ; i < 10; )
    {
      baz (i);
      i++;
    }

#pragma omp for
 for (i = 0; ; i--)
    {
      if (i >= 10)
 break;
      baz (i);
    }

#pragma omp for
 for (i = 0;
       i < 10 && j > 4;
       i-=3)
    baz (i);

#pragma omp for
 for (i = 0;
       i < 10;
       i-=3, j+=2)
    baz (i);

  int m = 0;
#pragma omp for
 for (; m < 10; m++)
    baz (m);

  m = 0;
#pragma omp for
 for (int n = 0; m < 10; m++)
    baz (m);

#pragma omp for
 for (m = 0; m < 10; i++)
    baz (m);
}
