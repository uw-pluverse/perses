




typedef double vec __attribute__ ((__vector_size__ (16)));
vec c, d;

void
foo (void)
{
  vec a;
  vec b;
  a = c;
  b = a;
  d = b;
}

void
bar (void)
{
  vec a;
  vec b;
  a = c;
  b = a;
}
