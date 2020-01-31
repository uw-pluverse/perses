


void bar (int a[10][10][10]);
void
foo (int a[10][10][10], int **b, int x)
{
  int c[10][10][10];
 bar (a);
 bar (a);
 bar (c);
 bar (a);
 bar (a);
 bar (c);
}
