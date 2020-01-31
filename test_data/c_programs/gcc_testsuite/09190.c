


struct S
{
  volatile long vl;
  int i;
};
struct S s1, s2;

void
foo (int j, int c)
{
  int i;
  for (i = 0; i <= j; i++)
    {
      if (c)
 s2.vl += s1.vl;
      s1 = s2;
    }
}
