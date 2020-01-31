


struct { int a: 23, b: 9; } foo;
struct { int a: 23, b: 9; } bar;

void
f (void)
{
  bar.b = foo.b;
}
