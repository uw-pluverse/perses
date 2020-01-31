





extern __thread int i, j, k;
extern void bar(int *, int *, int *);
void foo(void)
{
  bar(&i, &j, &k);
}
