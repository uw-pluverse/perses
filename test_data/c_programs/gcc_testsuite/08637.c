




typedef int (* const A[4])(int);

extern const A *ga;

static int __attribute__((noinline))
bar (const A *f, int x)
{
  x = (*f)[2](x);
  x = (*f)[2](x);
  x = (*f)[2](x);
  ga = f;
  return x;
}

static int
zero (int x)
{
  return 0;
}

static int
addone (int x)
{
  return x + 1;
}

static int
sq (int x)
{
  return x * x;
}

static int
cube (int x)
{
  return x * x * x;
}

static const A a = {zero, addone, sq, cube};

int
g (int x)
{
  return bar (&a, x);
}

int
obfuscate (int x)
{
  return bar ((A *) 0, x);
}
