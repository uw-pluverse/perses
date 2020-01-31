



union U {
  int i;
};

int
main (void)
{
  union U *u = 0;
  return u->i;
}
