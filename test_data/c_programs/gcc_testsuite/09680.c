





void bar(int, int, int, int);
void foo(void)
{
  int a1, a2, b1, b2;

#pragma omp p shared(a1, a2) shared(b1, b2) default(none)
 bar(a1, a2, b1, b2);
}
