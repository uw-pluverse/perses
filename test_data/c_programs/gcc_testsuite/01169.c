


struct { unsigned a: 5, b: 8, c: 19; } foo;
struct { unsigned a: 3, b: 8, c: 21; } bar;

void
f (void)
{
  bar.b = foo.b;
}
