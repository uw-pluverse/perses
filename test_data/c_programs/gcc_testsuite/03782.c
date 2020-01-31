

struct foo
{
  unsigned aa : 1;
  unsigned a : 9;
  unsigned c : 16;
  unsigned d : 6;
};


unsigned
foo (a, b)
     struct foo a;
{
  return a.d == 0;
}
