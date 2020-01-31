


extern void bar(int);

void foo (void)
{
#pragma omp critical
 bar(0);



#pragma omp critical(foo)
 {
    bar(1);
    bar(2);
  }

#pragma omp critical
#pragma omp critical(foo)
 bar(3);
}
