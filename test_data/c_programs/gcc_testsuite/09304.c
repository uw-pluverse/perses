



union U
{
  long unsigned int m;
  float d;
} u;

int
foo (void)
{
  union U v = {
    (long unsigned int)&u
  };
  return u.d == v.d;
}
