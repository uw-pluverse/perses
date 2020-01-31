


struct { unsigned a: 23, b: 9; } foo;
struct { unsigned a: 23, b: 9; } bar;

void
f (void)
{
  bar.b = foo.b;
}
