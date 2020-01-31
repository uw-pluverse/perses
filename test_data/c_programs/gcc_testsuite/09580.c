

void
a17_2_wrong ()
{
  int x;
  int *i;
  float *r;
  i = &x;
  r = (float *) &x;
#pragma omp parallel
 {
#pragma omp atomic
 *i += 1;
#pragma omp atomic
 *r += 1.0;


  }
}
