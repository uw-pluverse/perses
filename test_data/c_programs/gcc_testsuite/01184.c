



struct foo { unsigned a: 3, b: 8, c: 21; };

struct foo
f (struct foo i)
{
  i.b = 42;
  return i;
}

struct foo
g (struct foo i, int j)
{
  i.b = j;
  return i;
}
