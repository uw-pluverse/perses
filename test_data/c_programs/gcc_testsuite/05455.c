


struct S
{
  int a[1];
  int z[256];
};

void foo (struct S *s, int i)
{
  struct S disappear;

  disappear.a[i] = 12;
  *s = disappear;
}
