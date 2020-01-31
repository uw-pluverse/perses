




void
foo (int x)
{
#pragma omp p num_threads (4) if (1) private (x)
 ;
#pragma omp p num_threads(4)if(1)private(x)
 ;
#pragma omp p num_threads (4), if (1) , private (x)
 ;
#pragma omp p num_threads(4),if(1),private(x)
 ;
#pragma omp p, num_threads (4), if (1), private (x)
 ;
#pragma omp p num_threads (4), if (1), private (x),
 ;
#pragma omp p num_threads (4), , if (1), private (x)
 ;
}
