



struct S { int a; };

int
f (struct S *x)
{
  int a = x->a;
  if (a)
    return f (x) + a;
  else
    return f (x);
}
