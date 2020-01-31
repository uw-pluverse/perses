


volatile int *a, *b;

void foo()
{
  int j, k;

 for (int i=0; i < 1000; ++i)
    a[i] = b[j];
}
