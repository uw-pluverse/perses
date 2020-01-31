



int *p;
void __attribute__((noinline,noclone))
bar (void)
{
  *p = 1;
}
int __attribute__((noinline,noclone))
foo (long int addr)
{
  int i;

  int **q = (int **)addr;

  *q = &i;
  i = 0;

  bar ();
  return i;
}
extern void abort (void);
int
main()
{
  if (foo ((long int)&p) != 1)
    abort ();
  return 0;
}
