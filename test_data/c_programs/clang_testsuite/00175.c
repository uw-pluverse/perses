void test() {
  void *vp;
  int *ip;
  char *cp;
  struct foo *fp;
  struct bar *bp;
  short sint = 7;
  if (ip < cp) {}
  if (cp < fp) {}
  if (fp < bp) {}
  if (ip < 7) {}
  if (sint < ip) {}
  if (ip == cp) {}
}
