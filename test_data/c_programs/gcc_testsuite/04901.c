




int a[3], b;
struct C { int x; int y; } c;

int bar (void), *baz (void);

void
foo (void)
{
 a[2] += bar ();
 b += bar ();
 c.y += bar ();
 *baz () += bar ();
}
