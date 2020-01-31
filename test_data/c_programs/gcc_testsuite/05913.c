


typedef union {
  int i;
  float f;
} U;

int foo(U *u, int b, int i)
{
  u->i = 0;
  if (b)
    u->i = i;
  return u->i;
}
