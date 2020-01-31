


#pragma omp section

int i;

void
foo (void)
{
#pragma omp section
 i++;
}
