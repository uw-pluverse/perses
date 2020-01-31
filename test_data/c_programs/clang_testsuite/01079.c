extern void bar(int[]);
void foo(int a)
{
  int var[a] __attribute__((__aligned__(16)));
  bar(var);
  return;
}
