

int *a, *b, *c;

void foo()
{
  int i, j;

#pragma simd
 for (i=0, j=5; i < 1000; i++)
    a[i] = b[j];
}
