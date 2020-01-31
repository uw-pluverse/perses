


struct X {
  char *a;

  int b;
};

void f (struct X *x)
{
  x->a[x->b] = 0;
}
