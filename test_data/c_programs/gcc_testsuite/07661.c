

int bar (int);
int *baz (int *);

void
foo (int a)
{
  while (bar (0))
    {
      int *c = baz (0);
      if (a)
 {
   int i = *baz (c);
 }
      bar (*baz (c));
    }
}
