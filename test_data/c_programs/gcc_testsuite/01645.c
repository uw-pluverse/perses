



struct pts {
  int c;
};

unsigned int bar (struct pts *a, int b);

struct pts * foo (struct pts *a, int b)
{
  return (struct pts *) bar (a, b);
}
