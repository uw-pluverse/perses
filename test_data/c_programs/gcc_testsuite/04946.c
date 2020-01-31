extern _Bool foo (void);

enum { A, B };

int
fn1 (_Bool b)
{
  int r = 0;

  r += b >= 0;
  r += b > 0;
  r += b < 0;
  r += b <= 0;

  r += b >= 1;
  r += b > 1;
  r += b < 1;
  r += b <= 1;

  r += foo () >= 0;
  r += foo () > 0;
  r += foo () < 0;
  r += foo () <= 0;

  r += foo () >= 1;
  r += foo () > 1;
  r += foo () < 1;
  r += foo () <= 1;

  r += b >= A;
  r += b > A;
  r += b < A;
  r += b <= A;

  r += b >= B;
  r += b > B;
  r += b < B;
  r += b <= B;


  r += 0 >= b;
  r += 0 > b;
  r += 0 < b;
  r += 0 <= b;

  r += 1 >= b;
  r += 1 > b;
  r += 1 < b;
  r += 1 <= b;

  r += 0 >= foo ();
  r += 0 > foo ();
  r += 0 < foo ();
  r += 0 <= foo ();

  r += 1 >= foo ();
  r += 1 > foo ();
  r += 1 < foo ();
  r += 1 <= foo ();

  r += A >= b;
  r += A > b;
  r += A < b;
  r += A <= b;

  r += B >= b;
  r += B > b;
  r += B < b;
  r += B <= b;

  return r;
}

int
fn2 (int i, int j)
{
  int r = 0;

  r += (i == j) >= 0;
  r += (i == j) > 0;
  r += (i == j) < 0;
  r += (i == j) <= 0;

  r += (i == j) >= 1;
  r += (i == j) > 1;
  r += (i == j) < 1;
  r += (i == j) <= 1;

  return r;
}
