



struct d
{ int a; };
void abort(void);
typedef struct d (*f) (int i);
f ff(void);
void test1()
{
  f t = ff();
  t(0);
}
