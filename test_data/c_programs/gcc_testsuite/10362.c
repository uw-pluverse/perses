



int *a, *b, c;

void foo()
{
#pragma simd
 for (int i=0; i < 1000; ++i)
    {
      a[i] = b[i];
      if (c == 5)
 return;
    }
}

void bar()
{
#pragma simd
 for (int i=0; i < 1000; ++i)
    {
    lab:
      a[i] = b[i];
    }
  if (c == 6)
    goto lab;
}

void baz()
{
  bad1:
#pragma omp parallel
 goto bad1;

  goto bad2;
#pragma omp parallel
 {
      bad2: ;
    }

#pragma omp parallel
 {
      int i;
      goto ok1;
      for (i = 0; i < 10; ++i)
 { ok1: break; }
    }
}
