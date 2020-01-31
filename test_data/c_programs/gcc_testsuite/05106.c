


typedef struct teststruct
{
  double d;
  int i1;
  char c1;
  float z;
  char c2;
  int i2;
} teststruct;

void link_error (void);

void cow (int i)
{
  teststruct a, b, c, d;

  a.d = 3.2;
  a.i1 = i;

  b = a;
  c = b;
  d = c;

  if (d.i1 != i)
    link_error ();
}
