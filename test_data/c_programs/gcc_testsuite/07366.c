

extern int foo (long int a, int b, int c);
extern long int bar (int a, int b, long int c);

__attribute__((noinline)) int
foo (long int a, int b, int c)
{
  return a + b + c;
}

__attribute__((noinline)) long int
bar (int a, int b, long int c)
{
  return a + b + c;
}
