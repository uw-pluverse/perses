


void bar (int a[10][10][10]);
void
foo (int a[10][10][10], int **b)
{
  int c[10][10][10];
 bar (a);
  int i = 1, j = 3, k = 2, l = 6;
 bar (a);
 {
    bar (c);
    bar (a);
  }
}
