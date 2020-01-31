


typedef struct {
  int i;
  int j;
  int k;
} Foo;

void bar(Foo*);
int foo(void)
{
  Foo a;
  a.i = 1;
  bar(&a);
  return a.i;
}
