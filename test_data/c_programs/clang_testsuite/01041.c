void foo(void)
{
  char a[1];
  int t = 1;
  ((char (*)[t]) a)[0][0] = 0;
}
