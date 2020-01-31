



struct T { int c; char d[]; };
struct T t = { 1, "a" };

int
baz (int i)
{
  return t.d[i];
}

int
main (void)
{
  baz (2);
  return 0;
}
