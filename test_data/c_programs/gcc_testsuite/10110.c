






struct a
{
  unsigned long b:24;
};

void
foo (struct a *t)
{
  t->b = 32;
}
