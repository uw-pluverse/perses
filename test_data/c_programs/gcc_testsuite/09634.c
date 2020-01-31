







int
foo (void)
{
  int i;
  unsigned int u;

#pragma omp for
 for (i = (-2147483647 - 1) + 6; i > (-2147483647 - 1) + 1; i--)
    ;
#pragma omp for
 for (i = (-2147483647 - 1) + 6; i >= (-2147483647 - 1) + 1; i--)
    ;
#pragma omp for
 for (i = (-2147483647 - 1) + 6; i > (-2147483647 - 1); i--)
    ;
#pragma omp for
 for (i = 2147483647 - 6; i < 2147483647 - 1; i++)
    ;
#pragma omp for
 for (i = 2147483647 - 6; i <= 2147483647 - 1; i++)
    ;
#pragma omp for
 for (i = 2147483647 - 6; i < 2147483647; i++)
    ;
#pragma omp for
 for (u = 6; u > 1; u--)
    ;
#pragma omp for
 for (u = 6; u >= 1; u--)
    ;
#pragma omp for
 for (u = 6; u > 0; u--)
    ;
#pragma omp for
 for (u = (2U * 2147483647 + 1) - 6; u < (2U * 2147483647 + 1) - 1; u++)
    ;
#pragma omp for
 for (u = (2U * 2147483647 + 1) - 6; u <= (2U * 2147483647 + 1) - 1; u++)
    ;
#pragma omp for
 for (u = (2U * 2147483647 + 1) - 6; u < (2U * 2147483647 + 1); u++)
    ;
}

int
bar (void)
{
  int i;
  unsigned int u;

#pragma omp for
 for (i = (-2147483647 - 1) + 6; i > (-2147483647 - 1) + 1; i -= 2)
    ;
#pragma omp for
 for (i = (-2147483647 - 1) + 6; i >= (-2147483647 - 1) + 1; i -= 2)
    ;
#pragma omp for
 for (i = (-2147483647 - 1) + 6; i > (-2147483647 - 1); i -= 2)
    ;
#pragma omp for
 for (i = 2147483647 - 6; i < 2147483647 - 1; i += 2)
    ;
#pragma omp for
 for (i = 2147483647 - 6; i <= 2147483647 - 1; i += 2)
    ;
#pragma omp for
 for (i = 2147483647 - 6; i < 2147483647; i += 2)
    ;
#pragma omp for
 for (u = 6; u > 1; u -= 2)
    ;
#pragma omp for
 for (u = 6; u >= 1; u -= 2)
    ;
#pragma omp for
 for (u = 6; u > 0; u -= 2)
    ;
#pragma omp for
 for (u = (2U * 2147483647 + 1) - 6; u < (2U * 2147483647 + 1) - 1; u += 2)
    ;
#pragma omp for
 for (u = (2U * 2147483647 + 1) - 6; u <= (2U * 2147483647 + 1) - 1; u += 2)
    ;
#pragma omp for
 for (u = (2U * 2147483647 + 1) - 6; u < (2U * 2147483647 + 1); u += 2)
    ;
}
