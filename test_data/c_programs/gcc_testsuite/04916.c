



void baz (void) __attribute__((noreturn));

void
foo (int x)
{
  if (x)
 for (int i = 0; i < 10; i++)
      baz ();
 for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k < 10; k++)
 baz ();
}
