extern int x;
int f() {
  int *p = &x;
  return *p;
}
