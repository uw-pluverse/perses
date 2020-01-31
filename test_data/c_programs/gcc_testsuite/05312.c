

extern void abort (void);
int a;

extern void __attribute__ ((malloc)) *foo ();

void bar (void)
{
  a = 1;
  foo ();
  if (a)
    abort ();
}
