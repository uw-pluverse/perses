

extern int foo (long int a, int b, int c);
extern long int bar (int a, int b, long int c);

int
foo (long int a, int b, int c)
{
  return a + b + c;
}

long int
bar (int a, int b, long int c)
{
  return a + b + c;
}
