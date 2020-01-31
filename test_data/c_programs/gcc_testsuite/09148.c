



extern void foo (int status) __attribute__ ((__noreturn__,__noinline__));
extern void bar (int status) __attribute__ ((__noreturn__,__noinline__));
extern void _Exit (int status) __attribute__ ((__noreturn__,__noinline__));

void
foo (int status)
{
  _Exit (status);
}

void
_Exit (int status)
{
  bar (status);
}
