




void foo(void)
{
  int x[8] __attribute__((aligned(64))) = { 1, 1, 1, 1, 1, 1, 1, 1 };
  bar (x);
}
