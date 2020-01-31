





int foo (int a)
{
  static void * const ar[] = { &&l2 };
  void *p = ar[a];
  goto *p;
l2:
  return 2;
}
