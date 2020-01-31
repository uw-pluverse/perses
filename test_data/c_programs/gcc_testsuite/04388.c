


union U {
  struct something *sth;
  void *nothing;
};

void
foo (union U *target, void *p)
{
  union U u;

  u.nothing = p;
  *target = u;
  return;
}
