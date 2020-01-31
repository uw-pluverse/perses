extern int bar (void);
extern int *p;
struct R { int a, b; } S;

void
andfn (int a, int b)
{
  if (a && a) {}
  if (!a && !a) {}
  if (!!a && !!a) {}
  if (a > 0 && a > 0) {}
  if (a < 0 && a < 0) {}
  if (a == 0 && a == 0) {}
  if (a <= 0 && a <= 0) {}
  if (a >= 0 && a >= 0) {}
  if (a == 0 && !(a != 0)) {}

  if (a && a && a) {}
  if ((a + 1) && (a + 1)) {}
  if ((10 * a) && (a * 10)) {}
  if (!!a && a) {}

  if (*p && *p) {}
  if (p[0] && p[0]) {}
  if (S.a && S.a) {}
  if ((_Bool) a && (_Bool) a) {}
  if ((unsigned) a && a) {}


  if (a && b) {}
  if (!a && !b) {}
  if (!!a && !!b) {}
  if (a > 0 && b > 0) {}
  if (a < 0 && b < 0) {}
  if (a == 0 && b == 0) {}
  if (a <= 0 && b <= 0) {}
  if (a >= 0 && b >= 0) {}

  if (a > 0 && a > 1) {}
  if (a > -2 && a > 1) {}
  if (a && (short) a) {}
  if ((char) a && a) {}
  if (++a && a) {}
  if (++a && ++a) {}
  if (a && --a) {}
  if (a && a / 2) {}
  if (bar () && bar ()) {}
  if (p && *p) {}
  if (p[0] && p[1]) {}
  if (S.a && S.b) {}
}

void
orfn (int a, int b)
{
  if (a || a) {}
  if (!a || !a) {}
  if (!!a || !!a) {}
  if (a > 0 || a > 0) {}
  if (a < 0 || a < 0) {}
  if (a == 0 || a == 0) {}
  if (a <= 0 || a <= 0) {}
  if (a >= 0 || a >= 0) {}
  if (a == 0 || !(a != 0)) {}

  if (a || a || a) {}
  if ((a + 1) || (a + 1)) {}
  if ((10 * a) || (a * 10)) {}
  if (!!a || a) {}

  if (*p || *p) {}
  if (p[0] || p[0]) {}
  if (S.a || S.a) {}
  if ((_Bool) a || (_Bool) a) {}
  if ((unsigned) a || a) {}


  if (a || b) {}
  if (!a || !b) {}
  if (!!a || !!b) {}
  if (a > 0 || b > 0) {}
  if (a < 0 || b < 0) {}
  if (a == 0 || b == 0) {}
  if (a <= 0 || b <= 0) {}
  if (a >= 0 || b >= 0) {}

  if (a > 0 || a > 1) {}
  if (a > -2 || a > 1) {}
  if (a || (short) a) {}
  if ((char) a || a) {}
  if (++a || a) {}
  if (++a || ++a) {}
  if (a || --a) {}
  if (a || a / 2) {}
  if (bar () || bar ()) {}
  if (p || *p) {}
  if (p[0] || p[1]) {}
  if (S.a || S.b) {}
}
