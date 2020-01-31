typedef struct foo {
  int X, Y;
} FOO;
static FOO foo[100];
int test() {
  return foo[4].Y;
}
