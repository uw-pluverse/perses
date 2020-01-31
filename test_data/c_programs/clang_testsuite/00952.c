extern int bar();
extern void foobar();
void foo(int s) {
  unsigned loc = 0;
  if (s) {
    if (bar()) {
      foobar();
    }
  } else {
    loc = 1;
    if (bar()) {
      loc = 2;
    }
  }
}
