

enum E1 { A, B, C };
enum E2 { D, E, F };

enum E1 g1;
enum E2 g2;

void
f1 ()
{
  int a;
  int d;
  enum E1 e1;
  enum E2 e2;
  a = A;
  a = !B;
  d = E;
  e1 = A;
  e1 = D;
  e1 = 0;
  e1 = (enum E1) 0;
  e1 = (enum E2) 0;
  e1 = e2;
  e1 = g1;
  e1 = g2;
  e2 = A;
  e2 = D;
}

struct s { enum E1 e1 : 3; };

void
f2 (struct s sv)
{
  sv.e1 = A;
  sv.e1 = D;
  g1 = sv.e1;
  g2 = sv.e1;
}

void
f3 (struct s *pv)
{
  pv->e1 = A;
  pv->e1 = D;
  g1 = pv->e1;
  g2 = pv->e1;
}
