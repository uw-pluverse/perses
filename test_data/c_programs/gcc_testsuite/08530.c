



void link_error (void);

enum A {
  A1 = 0,
  A2 = A1 - 1
};
enum B {
  B1 = 0u,
  B2 = B1 - 1
};
int main(void)
{
  enum A a = -1;
  enum B b = -1;

  if (!(a < 0))
    link_error ();
  if (!(A2 < 0))
    link_error ();
  if (!(b < 0))
    link_error ();
  if (!(B2 < 0))
    link_error ();

  return 0;
}

enum E1 { e10 = 2147483647, e11 };
enum E2 { e20 = (unsigned) 2147483647, e21 };
