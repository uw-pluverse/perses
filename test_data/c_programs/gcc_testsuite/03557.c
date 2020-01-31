

typedef long unsigned int size_t;
union U { int c; } foo;
int bar (void)
{
  return !(((size_t) &foo & 3) == 0 && !((size_t) &foo & 1));
}
