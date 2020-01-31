


const static int a;

int __attribute__((noinline))
foo(int i)
{
  const int *q;
  int b;
  if (i)
    q = &a;
  else
    q = &b;
  b = 1;

  return *q;
}

extern void abort (void);
int main()
{
  if (foo(1) != 0)
    abort ();
  return 0;
}
