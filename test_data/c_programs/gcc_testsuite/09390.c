





static int foo1;
static int foo2 = 1;

static void foo5(void) { }
static void foo6(void);
static void foo6(void) { }
static void foo7(void);
void foo7(void) { }

void foo9(void)
{
  foo1 = 2;
  foo2 = 3;
  foo5();
  foo6();
  foo7();
}
