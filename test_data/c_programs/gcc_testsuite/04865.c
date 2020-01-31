


void baz (int *);

void
foo (void)
{
  int i;
 for (i = 0; i < 100; i++)
    baz (&i);
}

void
bar (void)
{
  int i;
 {
 for (i = 0; i < 100; i++)
      baz (&i);
  }
}
