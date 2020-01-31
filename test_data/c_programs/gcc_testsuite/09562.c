





extern void bar(int);
void foo(void)
{
  int i;

#pragma omp parallel for default(none)
 for (i = 0; i < 10; i++)
    bar(i);
}
