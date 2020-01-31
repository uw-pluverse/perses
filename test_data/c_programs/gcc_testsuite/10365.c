



void *baz (void);

static void *
bar (void *x)
{
  x = baz ();
  return x;
}

void *
foo (void *x)
{
  return bar (x);
}
