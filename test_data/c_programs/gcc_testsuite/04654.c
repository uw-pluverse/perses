extern _Bool foo (void);
_Bool r;

enum { E = 4 };

void
fn1 (_Bool b)
{
  r = b == 2;
  r = b != 2;
  r = b < 2;
  r = b > 2;
  r = b <= 2;
  r = b >= 2;

  r = b == -1;
  r = b != -1;
  r = b < -1;
  r = b > -1;
  r = b <= -1;
  r = b >= -1;

  r = foo () == 2;
  r = foo () != 2;
  r = foo () < 2;
  r = foo () > 2;
  r = foo () <= 2;
  r = foo () >= 2;

  r = b == E;
  r = b != E;
  r = b < E;
  r = b > E;
  r = b <= E;
  r = b >= E;


  r = 2 == b;
  r = 2 != b;
  r = 2 < b;
  r = 2 > b;
  r = 2 <= b;
  r = 2 >= b;

  r = -1 == b;
  r = -1 != b;
  r = -1 < b;
  r = -1 > b;
  r = -1 <= b;
  r = -1 >= b;

  r = E == b;
  r = E != b;
  r = E < b;
  r = E > b;
  r = E <= b;
  r = E >= b;


  r = b == 0;
  r = b != 0;
  r = b == 1;
  r = b != 1;

  r = b <= 0;
  r = b > 0;
  r = b < 1;
  r = b >= 1;
}

void
fn2 (int i1, int i2)
{
  r = (i1 == i2) == 2;
  r = (i1 == i2) != 2;
  r = (i1 == i2) < 2;
  r = (i1 == i2) > 2;
  r = (i1 == i2) <= 2;
  r = (i1 == i2) >= 2;

  r = (i1 == i2) == -1;
  r = (i1 == i2) != -1;
  r = (i1 == i2) < -1;
  r = (i1 == i2) > -1;
  r = (i1 == i2) <= -1;
  r = (i1 == i2) >= -1;

  r = (i1 == i2) == E;
  r = (i1 == i2) != E;
  r = (i1 == i2) < E;
  r = (i1 == i2) > E;
  r = (i1 == i2) <= E;
  r = (i1 == i2) >= E;
}

void
fn3 (int n, _Bool b)
{

  r = b == n;
  r = b != n;
  r = b < n;
  r = b > n;
  r = b <= n;
  r = b >= n;

  r = n == E;
  r = n != E;
  r = n < E;
  r = n > E;
  r = n <= E;
  r = n >= E;
}
