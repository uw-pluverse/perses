


void fail(void) __attribute__((noreturn));
int bar(int);

int foo(int x) {
  int i;
  int s = 0;

  if (x <= 0) fail();
  for (i = 0; i < x; ++i) {

    s += bar(i/4);
  }
  return s;
}
