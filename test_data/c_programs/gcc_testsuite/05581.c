




struct a
{
  char t[10];
};

struct a *b;

void f(long unsigned int i)
{
  char *c = b->t;
  c[i] = 1;
}
