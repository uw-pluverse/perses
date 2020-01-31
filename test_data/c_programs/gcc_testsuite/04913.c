

int a[4];
int *p;
struct S { int x; int y[4]; } s;
int *bar(void);

void f1(void)
{
 a[4] += 1;
 *p += 1;
 s.x += 1;
 s.y[*p] += 1;
 s.y[*p] *= 42;
 *bar() += 1;
 *bar() *= 42;
}
