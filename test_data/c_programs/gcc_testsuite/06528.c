





typedef int a[];
typedef int a5[5];
typedef int a10[10];

a *f1 ();
a5 *f1 () { return 0; }

a *f2 (void);
a5 *f2 () { return 0; }

a *f3 ();
a5 *f3 (void) { return 0; }

a *f4 (void);
a5 *f4 (void) { return 0; }

void
g (void)
{
  a10 *x;
  x = f1 ();
  x = f2 ();
  x = f3 ();
  x = f4 ();
}
