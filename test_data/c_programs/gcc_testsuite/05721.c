


union U {
  float f;
  int i;
};

int foo (union U *p)
{
  union U u;
  p->f = 0.0;
  u = *p;
  return u.i;
}
