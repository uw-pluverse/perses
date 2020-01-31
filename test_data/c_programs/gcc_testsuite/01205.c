





void bar (int);

void
foo (int x, double y, double z)
{
  _Bool t = z >= y;
  if (!t || x)
    bar (t ? 1 : 16);
}
