struct S { int r; int *s; int t[10]; };
void bar (int *);

void
foo (int *p, int q, struct S t, int i, int j, int k, int l)
{
 bar (&q);
 bar (p);
 bar (p);
 bar (p);
 bar (p);
 bar (&q);
 bar (p);
 bar (&t.r);
 bar (&t.r);
 bar (&t.r);
 bar (&t.r);
 bar (&t.r);
 bar (t.s);
 bar (t.s);
 bar (t.s);
 bar (t.s);
 bar (t.s);
 bar (t.t);
 bar (t.t);
 bar (t.s);
 bar (t.s);
 bar (t.s);
 bar (t.s);
}
