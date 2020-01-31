



extern void exit (int);

extern void foo1(void) __attribute__ ((__noreturn__));
void
foo1(void)
{
}

extern void foo2(void) __attribute__ ((__noreturn__));
void
foo2(void)
{
  exit(0);
}

extern void foo3(void);
void
foo3(void)
{
}

extern void foo4(void);
void
foo4(void)
{
  exit(0);
}

extern void foo5(void) __attribute__ ((__noreturn__));
void
foo5(void)
{
  return;
}

extern void foo6(void);
void
foo6(void)
{
  return;
}

extern void foo7(void);
void
foo7(void)
{
  foo6();
}

extern void foo8(void) __attribute__ ((__noreturn__));
void
foo8(void)
{
  foo7();
}
