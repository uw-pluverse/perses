




struct A
{
  char base;
  int : 7;
  int x : 8;
};

int __attribute__ ((noinline, noclone))
f (void *p) {
  return ((struct A *)p)->x;
}

int
main ()
{
  char a = 0;
  return f (&a);
}
