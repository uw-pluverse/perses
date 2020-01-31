extern void use(char *a);
__attribute__((always_inline)) void helper_no_markers() {
  char a;
  use(&a);
}
void lifetime_test() {
  helper_no_markers();
}
