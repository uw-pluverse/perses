




int i,j,k, N;

extern void bar();

void
funk ()
{
#pragma omp parallel for ordered(3)
 for (i=0; i < N; i++)
    for (j=0; j < N; ++j)
      for (k=0; k < N; ++k)
    {



#pragma omp ordered depend(sink:i-8,j-2,k+2) depend(sink:i, j-1,k) depend(sink:i-4,j-3,k+6) depend(sink:i-6,j-4,k-6)




 bar();
#pragma omp ordered depend(source)
 }
}
