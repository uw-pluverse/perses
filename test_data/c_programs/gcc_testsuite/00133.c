




extern void foo (void);

void
isr1 (void)
{
  foo ();
}

void
isr2 (void)
{
  foo ();
}
