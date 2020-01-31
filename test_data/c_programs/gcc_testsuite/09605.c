




int
foo (void)
{
  int a[2], b[2], c[2];
  int *ap = &a[0];
  int *bp = &b[0];
  int *cp = &c[0];

#pragma omp parallel for
 for (unsigned int idx = 0; idx < 2; idx++)
    {
      ap[idx] = 1;
      bp[idx] = 2;
      cp[idx] = ap[idx];
    }

  return *cp;
}
