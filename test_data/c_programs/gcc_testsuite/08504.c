


int bar (int);
void baz (int);

void
foo (int y)
{
  int a;
  if (y)
    baz (bar (7) + 6);
  else
    baz (bar (7) + 6);
}
