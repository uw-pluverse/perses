





extern __thread int thr;

static int x;

static void
bar (void)
{
  x = 1;
}

static void



foo (const char *x, void *y, int *z)
{
  bar ();
}

void
test (const char *x, void *y)
{
  foo (x, y, &thr);
}
