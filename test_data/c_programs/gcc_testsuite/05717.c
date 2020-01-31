




void bla (int);
int bar (void);

void foo(void)
{
  int k;

  goto forward;
back:
  bla (k);
  return;

forward:
    {
      int i = bar ();

      k = i;

      goto back;
    }
}
