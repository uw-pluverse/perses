



void bar (int i);
void baz (int *);

void
foo (int *x)
{
  if (*x < 0)
    {
      baz (x);
      return;
    }
  bar (*x);
}
