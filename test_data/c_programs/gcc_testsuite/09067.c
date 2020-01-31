




extern __thread unsigned long long a[10];
extern __thread struct S { int a, b; } b[10];

unsigned long long
foo (long x)
{
  return a[x];
}

struct S
bar (long x)
{
  return b[x];
}


extern __thread unsigned __int128 c[10];

unsigned __int128
baz (long x)
{
  return c[x];
}
