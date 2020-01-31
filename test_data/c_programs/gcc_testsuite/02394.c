






extern void abort (void);

int
foo (void)
{
  char s[2] = "";
  return 0 == s[1];
}

char *t;

int
main (void)
{
  {
    char s[] = "x";
    t = s;
  }
  if (foo ())
    exit (0);
  else
    abort ();
}
