




int a[3];

void foo()
{
  int i, j;

  for (i = 1; i >= 0; --i)
    for (j = i; j >= 0; --j)
      a[i+j] = 0;
}
