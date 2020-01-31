

void foo()
{
  int i;

#pragma omp parallel default(none)
 {
#pragma omp parallel
 {
#pragma omp parallel default(none)
 {
    i++;
 }
      }
    }
}
