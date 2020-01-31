char *g0(char** argv, int argc) { return argv[argc]; }
char *g(char **argv) {
  f(g0, argv, 1, 2, 3);
}
char *i0(char **argv, int argc) { return argv[argc]; }
char *i(char **argv) {
  h(i0, argv, 1, 2, 3);
}
