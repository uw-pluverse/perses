char *foo1 (char *p, unsigned int x)
{
  return p - (x & ~1);
}

char *foo2 (char *p, unsigned int x)
{
  return p - (x & 6);
}
