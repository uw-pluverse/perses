




void bar (const char *, ...);

void
foo (const char *x, long double y, int z)
{
  if (z >= 0)
    bar (x, z, y);
  else
    bar (x, y);
}
