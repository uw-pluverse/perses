



struct S { int f : 4; } a;

void
foo (void)
{
  a.f = foo;
}
