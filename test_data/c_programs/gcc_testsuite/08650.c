


static void __attribute__((noinline,noclone))
clobber_me (int *p, int how)
{
  *p = how;
}





static int
foo (void)
{
  int a = 0;
  clobber_me (&a, 1);
  return a;
}

extern void abort (void);

int main()
{
  if (foo () != 1)
    abort ();

  return 0;
}
