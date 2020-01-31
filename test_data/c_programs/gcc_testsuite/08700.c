




typedef int (* const A[4])(int);

typedef struct S
{
  int add_offset;
  A a;
} S;

extern const S *gs, *hs;

static int __attribute__((noinline))
foo (const S f, int x)
{
  gs = &f;
  x = f.a[2](x);
  x = f.a[2](x);
  x = f.a[2](x);
  return x;
}

static int __attribute__((noinline))
bar (const S f, int x)
{
  hs = &f;
  return foo (f, x);
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

static const S s = {64, {zero, addone, sq, cube}};

int
h (int x)
{
  return bar (s, x);
}
