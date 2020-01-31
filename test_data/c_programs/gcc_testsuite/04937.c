







static inline __attribute__ ((always_inline)) int
foo (int x)
{
  return x;
}

int
bar (int x)
{
  return foo (x);
}
