void
foo (char *i)
{
}


int
main (void)
{
  int size = sizeof (int);
  foo (__builtin_constant_p(size) ? "1" : "0");
  foo (__builtin_constant_p(size) ? "1" : "0");
  exit (0);
}
