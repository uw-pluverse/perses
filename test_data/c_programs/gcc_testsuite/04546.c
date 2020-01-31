





enum A { B = -3, C = 2 } a;
_Bool b;

__attribute__((noinline, noclone)) enum A
foo (_Bool *p)
{
  *p = b;
  return a;
}

int
main ()
{
  char c = 4;
  int d = 9;
  if (sizeof (int) != sizeof (a) || sizeof (b) != 1)
    return 0;
  __builtin_memcpy (&a, &d, sizeof (int));
  __builtin_memcpy (&b, &c, 1);
  _Bool e;
  foo (&e);
  return 0;
}
