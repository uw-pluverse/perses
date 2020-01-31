



void foo (int, int);

void
bar (int *x)
{
  foo (*x++, sizeof (*x));
}

void
baz (int *x)
{
  foo (*x, sizeof (*x++) + sizeof (*x++));
}
