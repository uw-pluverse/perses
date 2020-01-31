






struct a
{
  unsigned int b:24;
};

void
foo (struct a *t)
{
  t->b = 32;
}
