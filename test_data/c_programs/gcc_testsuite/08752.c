



struct bah {int a,b,d;};
void test3 (int, int, int, int, int);

__attribute__ ((noinline))
void test(int a,int b,int c,int d,int e)
{
  test3(a,b,c,d,e);
}
inline
static void bar (int parm1, int parm2)
{
  int i;
  for (i = 0; i<10; i++)
    {
      test (0,0,parm1,parm2,i);
    }
}
void foo (int invariant)
{
  int i;
  for (i = 0; i<10; i++)
    {
      bar (i, invariant);
    }
}
