


typedef struct S
{
  int add_offset;
  int (*call)(int);
} S;

static int
bar (const S f, int x)
{
  x = f.call (x);
  return x;
}

static int
thisisthetarget (int x)
{
  return x * x;
}

int
outerfunction (int x)
{
  return bar ((S){16, thisisthetarget}, x);
}
