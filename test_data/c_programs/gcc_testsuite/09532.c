







int foo (int a)
{
  static const int ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
  void *p = &&l1 + ar[a];
  goto *p;
  l1:
    return 1;
  l2:
    return 2;
}
