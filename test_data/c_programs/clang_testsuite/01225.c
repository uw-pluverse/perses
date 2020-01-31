void f(const char *cpc) {
  const char *cpc2 = (const char*)cpc;
  char *pc = (char*)cpc;
  typedef const char *Typedef1;
  (Typedef1)cpc;
}
