




struct L { unsigned int l[2]; };
union U { double a; struct L l; } u;

void
foo (double a, struct L *p)
{
  u.a = a;
  struct L l = u.l, m;
  m.l[0] = (((l.l[1] & 0xff000000) >> 24)
     | ((l.l[1] & 0x00ff0000) >> 8)
     | ((l.l[1] & 0x0000ff00) << 8)
     | ((l.l[1] & 0x000000ff) << 24));
  m.l[1] = (((l.l[0] & 0xff000000) >> 24)
     | ((l.l[0] & 0x00ff0000) >> 8)
     | ((l.l[0] & 0x0000ff00) << 8)
     | ((l.l[0] & 0x000000ff) << 24));
  *p = m;
}

void
bar (double a, struct L *p)
{
  foo (a, p);
}
