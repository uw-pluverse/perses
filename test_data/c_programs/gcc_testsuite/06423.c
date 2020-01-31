



struct x
{
  int i;
};
void bar(struct x*, int *);

void foo(struct x *y)
{
  bar(y++, &y->i);
}

void zz(int a, int *b)
{
  *b = a;
}

void baz(void) {
  int a = 5;
  zz(++a, &a);
}
