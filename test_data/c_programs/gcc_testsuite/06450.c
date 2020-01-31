




int v[128];

union R { int c; union R *p; };
extern union R *w[];
typedef struct { int t; } T;
typedef struct { void *u; } U;
union R *fn1 (void);
void fn2 (int, const char *, union R *);
void fn3 (void);
int fn4 (union R *);
void foo (U *x);

void
foo (U *x)
{
  T *a = x->u;
  while (1)
    {
      union R *b;
      b = fn1 ();
      if (b != w[0] && !(v[b->p->c] == 1))
 {
   fn2 (a->t, "foobar", b->p);
   b = w[0];
 }
      if (b != w[0])
 fn3 ();
      if (w[0] && b != w[0])
 fn4 (b->p);
      if (b != w[0] && (v[b->p->c] == 1) && fn4 (b->p))
 break;
    }
}
