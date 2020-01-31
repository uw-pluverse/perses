






extern void abort (void);

long long __attribute__((noinline))
foo ()
{
  return 3;
}

int __attribute__((noinline))
boo ()
{
  return foo ();
}

int
main ()
{
  if (boo () != 3)
    abort ();
}
