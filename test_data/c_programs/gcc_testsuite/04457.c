






enum { U };

void
fn1 (int a, int *p)
{
  if (a > a);
  if (a < a);
  if (a >= a);
  if (a <= a);
  if (a == a);
  if (a != a);
  if (a == a);
  if ((unsigned) a != (unsigned) a);
  if ((a + 1) <= (a + 1));
  if (1 ? a == a : 0);
  if (fn1 == fn1);
  if (*p == *p);

  volatile int v = 5;
  if (v == v);
  if (v != v);
}

void
fn2 (int a)
{
  if (sizeof (int) >= 4);
  if (sizeof (char) != 1);
  if (sizeof (long) != sizeof (long long));
  if (0 < sizeof (short));
  if (5 != 5);
  if (5 > 5);
  if (5 == 5);
  if (3 + 4 == 6 + 1);
  if ((unsigned) a != (unsigned long) a);
  if (U == U);
  if (U > 0);
}

void
fn3 (int i, int j)
{
  static int a[16];
  static int b[8][8];

  if (a[5] == a[5]);
  if (a[5] != a[5]);
  if (a[5] != a[5]);
  if (a[i] == a[i]);
  if (b[5][5] == b[5][5]);
  if (b[5][5] >= b[5][5]);
  if (b[5][5] == b[5][5]);
  if (b[i][j] != b[i][j]);
  if (b[i][5] < b[i][5]);
  if (b[5][j] < b[5][j]);
  if ((a[i] + 4) == (4 + a[i]));
}

int
fn4 (int x, int y)
{
  return x > x ? 1 : 0;
}
