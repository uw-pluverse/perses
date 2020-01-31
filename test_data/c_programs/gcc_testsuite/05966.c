




struct a
{
  int t[10];
};

void f(struct a * b, long unsigned int i)
{
  int *c = b->t;
  c[i] = 1;
}
