typedef int vec __attribute__((vector_size(16)));

vec i,j;
extern vec a, b, c;

extern int p, q, z;
extern vec foo (int);

vec
foo (int x)
{
  return foo (p ? q :z) > a;
}

vec
bar (int x)
{
  return b > foo (p ? q :z);
}
