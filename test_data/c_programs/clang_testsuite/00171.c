void test1()
{
#pragma clang __debug captured x
  {
  }
}
void test2()
{
#pragma clang __debug captured
  int x;
}
