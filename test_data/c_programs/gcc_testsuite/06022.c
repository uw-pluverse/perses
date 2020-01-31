


typedef int intflt;






struct X {
  int i;
  union {
    intflt j;
    intflt k;
    float f;
  } u;
};

intflt foo(intflt j)
{
  struct X a;

  a.u.j = j;
  a.u.f = a.u.f;
  a.u.f = a.u.f;
  a.u.j = a.u.j;
  a.u.f = a.u.f;
  return a.u.k;
}
