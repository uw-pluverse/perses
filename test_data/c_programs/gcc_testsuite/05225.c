


int *i;
void __attribute__((noinline))
foo (void)
{
  *i = 1;
}
int __attribute__((noinline))
bar(int local_p)
{
  int x = 0;
  int *j;
  int **p;
  if (local_p)
    p = &j;
  else
    p = &i;
  *p = &x;
  foo ();
  return x;
}
extern void abort (void);
int main()
{
  int k = 2;
  i = &k;
  if (bar (1) != 0 || k != 1)
    abort ();
  if (bar (0) != 1)
    abort ();
  return 0;
}
