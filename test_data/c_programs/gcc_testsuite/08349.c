





struct s;
struct t { struct s *p; } x;

void
f (void)
{

  struct s { int a; } y;
  x.p = &y;
}
