




struct s { int a; int b; };
union u { int c; int d; };

void
foo (void)
{
  (int) { 1 };

  (struct s) { 1, 2 };

  (union u) { 1 };

  (int [1]) { 1 };

}
