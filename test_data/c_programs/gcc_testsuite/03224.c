



void foo (c)
     char c;
{
  (void) &c;
}

int bar (void);

void baz (void)
{
  foo (bar ());
}
