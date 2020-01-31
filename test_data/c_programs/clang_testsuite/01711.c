static int a;
int bar() {
  extern int a;
  return a;
}
static int a;
