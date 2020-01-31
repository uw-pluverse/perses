






extern void bar (int);
extern void foo (void) __attribute__ ((interrupt("IRQ")));

void foo ()
{
  bar (0);
}
