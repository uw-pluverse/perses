



char g[] = "g";

void
foo (void)
{
#pragma omp parallel sections firstprivate (g) lastprivate (g)
 {
#pragma omp section
 g[0] = 'h';
  }
}
