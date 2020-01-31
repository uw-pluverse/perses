





extern int foo __attribute__ ((visibility ("hidden")));
int f () {
  return foo;
}
