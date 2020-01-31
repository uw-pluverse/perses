


struct object { int field; };
void o(struct object *);
int globl;
void t(int x)
{
  struct object a, b;
  struct object *p;
  o(&a);
  if (x)
    p = &a;
  else
    p = &b;
  p->field = 1;
  globl = 0;
  return;
}
