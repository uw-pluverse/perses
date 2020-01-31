



union u { int i; };
typedef union u uu;
union u a;
uu b;

void
foo (void)
{
  a = (union u) b;
  a = (uu) b;
  b = (union u) a;
  b = (uu) a;
}
