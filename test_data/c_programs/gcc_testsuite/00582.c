




struct S { short int i; };

struct S foo (short int i)
{
  struct S s;
  s.i = i;
  return s;
}
