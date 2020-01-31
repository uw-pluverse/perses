


extern void bar(int);

void foo (void)
{
#pragma omp master
 bar(0);
}
