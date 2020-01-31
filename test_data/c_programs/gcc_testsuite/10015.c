



struct S { long int a, b; } e;
__thread struct S s;

void
foo (void)
{
  s = e;
}
