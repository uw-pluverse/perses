




void abort (void);
struct a
{
  int i;
} *a;
int f(void)
{
  int *ii = &a->i;
  void *l;
  a->i = 1;
  if (*ii)
   l = &&l1;
  else
   l = &&l2;
  goto *l;
l1:
  return 0;
l2:
  abort ();
}
