int bar();
int foo()
{
  int a,b,c;
  a = b + c;
  b = bar();
  c = bar();
  return a + b + c;
}
