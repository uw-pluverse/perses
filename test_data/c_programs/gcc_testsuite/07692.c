





void
foo (void)
{
  static int a1 = 1 << 31;
  static int a2 = 10 << 30;
  static int a3 = 100 << 28;
  static int a4 = (-2147483647 - 1) / -1;
}
