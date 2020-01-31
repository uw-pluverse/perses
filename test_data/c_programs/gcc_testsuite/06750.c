

extern void abort (void);
struct X {

  unsigned long i : 33;



};
unsigned long __attribute__((noinline))
foo (struct X *p)
{
  return ~p->i;
}
int main()
{
  struct X x;
  x.i = -1;
  if (foo (&x) != 0)
    abort ();
  return 0;
}
