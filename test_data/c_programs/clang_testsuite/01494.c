typedef int (*MyFnTyA)(int *, char *);
int bar(char *a, int *b) { return 0; }
int foo(MyFnTyA x) { return 0; }
void baz() {
  foo(&bar);
}
