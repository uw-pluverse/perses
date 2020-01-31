


extern int omp_get_num_threads (void);
int x, y, t, z[1000];
#pragma omp threadprivate(x)
void
a24 (int a)
{
  const int c = 1;
  int i = 0;
  int l = 0;
#pragma omp parallel default(none) private(a) shared(z)
 {
    int j = omp_get_num_threads ();



    x = c;

    z[i] = y;



#pragma omp for firstprivate(y)
 for (i = 0; i < 10; i++)
      {
 z[i] = y;

      }
    z[l] = t;


  }
}
