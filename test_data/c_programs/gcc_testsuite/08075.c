



int foo(int *p, int n)
{
  int i, j, k = 0;




  for (i = 0; i < 2; ++i, p += n)
    for (j = 0; j < 2; ++j)
      k += p[j];

  return k;
}
