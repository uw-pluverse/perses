



struct bah {int a,b,d;};

static int do_work (struct bah s)
{
  return s.a*s.b/s.d;
}
int foo (int invariant)
{
  int i;
  struct bah s = {invariant,invariant,invariant};
  int sum = 0;
  for (i = 0; i<10; i++)
    {
      sum += do_work (s);
    }
  return sum;
}
