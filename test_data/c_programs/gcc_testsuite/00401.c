



void foo ()
{
  long l; void *p;
  volatile int x;

  __builtin_unwind_init ();
  x = 12;
  __builtin_eh_return (l, p);
}
