



void
foo (char *p)
{
}

char *
bar (void)
{
  const char *s = "foo";
  char *s1 = s;
  s1 = s;
  foo (s);
  return s;
}
