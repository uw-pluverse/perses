

void foo()
{
  int i;

#pragma omp for nowait
 for (i = 0; i < 10; ++i) ;

#pragma omp for nowait nowait
 for (i = 0; i < 10; ++i) ;

#pragma omp for ordered
 for (i = 0; i < 10; ++i) ;

#pragma omp for ordered ordered
 for (i = 0; i < 10; ++i) ;
}
