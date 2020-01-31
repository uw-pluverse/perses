





extern const char a[];

int
foo (const char *p)
{
  return (p > a) ? 0 : 2;
}
