



extern void bar(void);
void foo(void)
{
#pragma omp parallel num_threads(10)
 bar();
}
