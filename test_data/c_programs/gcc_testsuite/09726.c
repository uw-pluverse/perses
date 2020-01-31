




int v1;
typedef struct A A;
typedef int i;
#pragma omp threadprivate (i)
#pragma omp threadprivate (A)
#pragma omp threadprivate (v1)

void foo ()
{
  static int v4;
  {
    static int v5;
#pragma omp threadprivate (v4, v5)
 }
}
