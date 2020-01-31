



void foo (void) __attribute__((__longcall__));
int baz (void) __attribute__((__longcall__));

int
bar (void)
{
  foo ();
  return baz () + 1;
}
