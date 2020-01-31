


int i, j;

void
f1 (void)
{
#pragma omp for linear (i:1)
 for (i = 0; i < 32; i++)
    ;
}

void
f2 (void)
{
#pragma omp distribute parallel for linear (i:1)
 for (i = 0; i < 32; i++)
    ;
}

void
f3 (void)
{
#pragma omp parallel for linear (i:1) collapse(1)
 for (i = 0; i < 32; i++)
    ;
}

void
f4 (void)
{
#pragma omp for linear (i:1) linear (j:2) collapse(2)
 for (i = 0; i < 32; i++)
    for (j = 0; j < 32; j+=2)
      ;
}

void
f5 (void)
{
#pragma omp target teams distribute parallel for linear (i:1) linear (j:2) collapse(2)
 for (i = 0; i < 32; i++)
    for (j = 0; j < 32; j+=2)
      ;
}

void
f6 (void)
{
#pragma omp parallel for linear (i:1) collapse(2) linear (j:2)
 for (i = 0; i < 32; i++)
    for (j = 0; j < 32; j+=2)
      ;
}

#pragma omp declare target to (i, j, f2)

