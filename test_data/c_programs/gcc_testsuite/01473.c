



extern void bar(int*);
int foo()
{
  int x;
  bar(&x);
  return x;
}
