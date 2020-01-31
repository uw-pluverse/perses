


void
f1 (void)
{
  unsigned int a = -5;
  (void) a;
}

int
f2 (void)
{
  return 3.1f;
}

int f3 (char *);

int
f4 (void)
{
  char buf[131072];
  return f3 (buf);
}
