int foo(int i) {
  switch (i) {
  default:
    if (i == 1)
      return 0;
    (void)1;
  case 0:
    return 2;
  (void)1;
  label: ;
  }
}
void bar() {
  { while (0) { switch (0) {
default: ;
  }}}
}
void baz() {
  for (;;)
    switch (0) default: return;
}
int main(int argc, const char *argv[]) {
  foo(3);
  return 0;
}
