


struct x
{
  int a[16];
  int b[16];
  int c[16];
};

extern void foo (int, int, int);

void
f (struct x *p, unsigned int n)
{
  foo (p->a[n], p->c[n], p->b[n]);
  if (n > 3)
    {
      foo (p->a[n], p->c[n], p->b[n]);
      if (n > 12)
 foo (p->b[n], p->a[n], p->c[n]);
    }
}
