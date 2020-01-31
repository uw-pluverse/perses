


int
main (void)
{
#pragma omp parallel
 {
    extern void foo (void);
    foo ();
  }
  return 0;
}
