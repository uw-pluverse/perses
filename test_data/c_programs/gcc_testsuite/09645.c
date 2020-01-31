


extern void bar(int);

void foo (void)
{
#pragma omp ordered
 bar(0);

#pragma omp ordered
 {
    bar(1);
    bar(2);
  }
}
