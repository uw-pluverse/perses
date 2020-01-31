


struct S
{
  long m;
};

struct S
fn1 (struct S *a)
{
  if (a->m)
    a->m |= 2;
  return *a;
}
