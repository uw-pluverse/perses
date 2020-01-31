




typedef union U
{
  struct
  {
    unsigned int a;
    int b;
  };
  long long c;
} *T;

int foo (T x)
{
  int r = x->a + x->b;
  return r;
}
