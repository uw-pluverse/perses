struct t
{
  int bar;
};

struct t2
{
  struct t *s;
};

void test1 ()
{
  struct t *s = (void *)0;
  s->bar = 1;
}

void test2 (struct t *s)
{
  if (s == (void *)0 && s->bar > 2)
    return;

  s->bar = 3;
}

void test3 (struct t *s)
{
  if (s != (void *)0 || s->bar > 2)
    return;

  s->bar = 3;
}

int test4 (struct t *s)
{
  if (s != (void *)0 && s->bar > 2)
    return 1;
  return 0;
}

int test5 (struct t *s)
{
  if (s == (void *)0 || s->bar > 2)
    return 1;
  return 0;
}

int test6 (struct t2 *s)
{
  if (s->s == 0 && s->s->bar == 0)
    return 1;
  return 0;
}

int test7 (struct t *s)
{
  s = 0;
  return s->bar;
}

int test8 ()
{
  return ((struct t *)0)->bar;
}

void test9 (struct t **s)
{
  if (s == 0)
    *s = 0;
}
