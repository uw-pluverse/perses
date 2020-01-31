


void bar(void);
void foo(void)
{
#pragma omp critical (xyzzy)
 bar();
}
