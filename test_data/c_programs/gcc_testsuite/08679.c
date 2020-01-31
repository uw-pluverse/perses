


static void __attribute__((noinline,noclone))
foo (int *p)
{
  *p = 1;
}

extern void abort (void);

int main()
{
  int i = 0;
  foo (&i);
  if (i != 1)
    abort ();
  return 0;
}
