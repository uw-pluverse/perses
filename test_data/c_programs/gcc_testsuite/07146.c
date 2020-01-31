



struct X {
  float d;
  float b[];
};

struct X __attribute__((noinline))
foo (float d)
{
  struct X x;
  x.d = d;
  return x;
}
extern void abort (void);
int main()
{
  struct X x = foo(3.0);
  if (x.d != 3.0)
    abort ();
  return 0;
}
