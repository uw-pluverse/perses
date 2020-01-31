struct T { int a; int *b; };
struct S { int *s; char u; struct T v; long x; };

void bar (int *);

int
main ()
{
  int a[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  struct S s = { a, 5, { 6, a + 5 }, 99L };
 ;
 bar (&s.v.a);
 ;
 ;
 bar (s.s);
  return 0;
}
