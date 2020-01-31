


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
