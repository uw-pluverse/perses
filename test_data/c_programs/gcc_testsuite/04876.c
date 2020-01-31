



int
foo (int n)
{
  int a[10][10];
  int x, y;
 for (x = 0; x < n; x++)
    for (y = 0; y < n; y++)
      a[x][y] = x + y * y;
  return a[0][0];
}
