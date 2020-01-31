struct S { int i : 1; int j : 4; long long k : 25; };
void bar (struct S, int);

void
foo (struct S a, struct S b, struct S c, struct S d)
{
 bar (a, 0);
 bar (a, b.i);
 bar (a, b.j);
 bar (a, b.k);
 {
 }
}
