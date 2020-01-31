



union R { int c; union R *p; };
extern union R *w[];
typedef struct { int t; } T;
typedef struct { void *u; } U;
union R *fn1 (void);
void fn2 (int, const char *, union R *);
void fn3 (void);
int fn4 (union R *);
void foo (U *x);

union R *w[10];

union R *
fn1 (void)
{
  return (union R *) 0;
}

void
fn2 (int x, const char *y, union R *z)
{
}

void
fn3 (void)
{
}

int
fn4 (union R *x)
{
  return 0;
}

int
main ()
{
  return 0;
}
