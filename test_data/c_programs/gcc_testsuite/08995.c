




struct A { int i[100]; };

int b;

struct A f ()
{
  struct A a;
  if (b)
    {
      a.i[0] = 42;
      return a;
    }
  else
    {
      a.i[42] = 1;
      return a;
    }
}
