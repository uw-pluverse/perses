



extern void abort (void);

union U { int i; char c[4]; short s[2]; };

char __attribute__((noinline,noclone)) foo(int i)
{
  union U u;
  u.i = i;


  return u.c[0];





}

short __attribute__((noinline,noclone)) baz(int i)
{
  union U u;
  u.i = i;


  return u.s[0];





}

char __attribute__((noinline,noclone)) bar(int j)
{
  union U u;
  u.i = j;

  return u.c[2];
}

int main()
{
  if (foo (0x01020304) != 0x04)
    abort ();
  if (baz (0x01020304) != 0x0304)
    abort ();
  return 0;
}
