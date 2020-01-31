



__attribute__((noinline)) int
bar (int *x)
{
  return *x++;
}

int
main ()
{
  static int var1_s;
  static int *var1_t = &var1_s;

  return bar (var1_t) != 0;
}
