



int i;
#pragma omp threadprivate (i)

void foo()
{
  _Complex int j;
#pragma omp parallel copyin (i) reduction (&&:j)
 ;
}
