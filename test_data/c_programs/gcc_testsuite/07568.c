



int *ip __attribute__((used));
const int *cip __attribute__((used));
int * restrict irp __attribute__((used));
int * const icp __attribute__((used));
const int * restrict cirp __attribute__((used));
int * const restrict icrp __attribute__((used));
const int * const restrict cicrp __attribute__((used));

int * const volatile restrict cvirp __attribute__((used));
const volatile int * restrict pcvir __attribute__((used));

static __attribute__((noclone, noinline)) void *
cpy (void * restrict s1, const void * restrict s2, unsigned int n)
{
  char *t1 = s1;
  const char *t2 = s2;
  while(n-- > 0)
    *t1++ = *t2++;
  return s1;
}

int
main (int argc, char **argv)
{
  void *foo = 0;
  if (argc > 16)
    foo = cpy (argv[0], argv[1], argc);

  return foo != 0;
}
