



struct S { int i; };
struct S foo (void);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"

int
main ()
{
  foo ();
  return 0;
}

#pragma GCC diagnostic pop

