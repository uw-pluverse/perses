__attribute__ ((__noreturn__)) extern void fail (void);

char x;




void foo (const unsigned char y)
{
   ((void) (__builtin_expect((!! y == y), 1) ? 0 : (fail (), 0)));
   x = ! y;
}



int foo2 (int arg)
{
  if (arg != !arg)
    fail ();
  if (arg)
    fail ();
}
