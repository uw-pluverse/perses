


struct { int a: 13, b: 19; } foo;
struct { int a: 13, b: 19; } bar;

void
f (void)
{
  bar.b = foo.b;
}
