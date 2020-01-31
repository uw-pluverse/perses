



extern void baz (int);

void
foo (void)
{
  int i;
#pragma omp parallel for shared (i)
 for (i = 0; i < 2; i++)
    baz (i);
}

void
bar (void)
{
  int j = 0;
#pragma omp parallel shared (j)
 {
    j++;
#pragma omp for
 for (j = 0; j < 2; j++)
      baz (j);
  }
}
