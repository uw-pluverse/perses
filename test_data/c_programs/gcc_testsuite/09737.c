



int
main (void)
{
#pragma omp parallel default(none)
 {
    static int s;
    int t = 0;
#pragma omp atomic
 s++;
    t++;
  }
#pragma omp task default(none)
 {
    static int s;
    int t = 0;
#pragma omp atomic
 s++;
    t++;
  }
}
