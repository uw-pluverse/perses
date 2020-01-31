






__attribute__((vector_size((4)*sizeof(int)))) int
foo (__attribute__((vector_size((4)*sizeof(int)))) int x)
{
  return (x == x) + (x != x) + (x > x)
  + (x < x) + (x >= x) + (x <= x);
}

int
main (int argc, char *argv[])
{
  __attribute__((vector_size((4)*sizeof(int)))) int t = {argc, 2, argc, 42};
  __attribute__((vector_size((4)*sizeof(int)))) int r;
  int i;

  r = foo (t);

  for (i = 0; i < 4; i++)
    if (r[i] != -3)
      __builtin_abort ();

  return 0;
}
