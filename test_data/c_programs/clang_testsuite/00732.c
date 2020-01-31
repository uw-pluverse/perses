struct t {
  int x;
};
extern struct t *cfun;
int f(void) {
  if (!(cfun + 0))
    return 0;
  return cfun->x;
}
