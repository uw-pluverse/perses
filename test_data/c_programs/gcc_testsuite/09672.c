




int thr1, thr2;
#pragma omp threadprivate (thr1, thr2)

void
foo (void)
{
#pragma omp task untied
 {
    thr1++;
    thr2 |= 4;
  }
}

void
bar (void)
{
#pragma omp task
 {
    thr1++;
    thr2 |= 4;
  }
}
