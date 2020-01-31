


extern void bar(int);

void foo (void)
{
  int i;

#pragma omp parallel for schedule (nonmonotonic : dynamic, 4)
 for (i = 0; i < 37; ++i)
    bar(i);
}
