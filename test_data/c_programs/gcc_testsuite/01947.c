




static void *ptr1, *ptr2;
static int i = 1;

static __inline__ void doit(void **pptr, int cond)
{
  if (cond) {
  here:
    *pptr = &&here;
  }
}

__attribute__ ((noinline))
static void f(int cond)
{
  doit (&ptr1, cond);
}

__attribute__ ((noinline))
static void g(int cond)
{
  doit (&ptr2, cond);
}

__attribute__ ((noinline))
static void bar(void);

int main()
{
  f (i);
  bar();
  g (i);






  exit (0);
}

void bar(void) { }
