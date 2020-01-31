extern int exfunc(int a);
static inline int hfunc1()
{
  return exfunc(1);
}
int func1() { return hfunc1(); }
int func2() { fluffy; return hfunc1(); }
