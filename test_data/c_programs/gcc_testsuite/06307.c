



static int
f0 (char *s0, char *s1)
{
  return __builtin_strlen (s0) > __builtin_strlen (s1);
}

int
f1 (char *s, int j)
{
  if (f0 (s, ""))
    return 1;
  return j;
}

void
f2 (char *s)
{
  f1 (s, 0);
}
