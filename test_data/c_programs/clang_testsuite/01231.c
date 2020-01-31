static const char A[] = "abc";
int strcmp(const char *, const char *);
int test_warning_patterns() {
  if (strcmp(A, "a"))
    return 0;
  if (strcmp(A, "a") != 0 ||
      strcmp(A, "b"))
    return 0;
  if (strcmp(A, "a") == 1)
    return 0;
  if (strcmp(A, "a") == -1)
    return 0;
  if (strcmp(A, "a") < '0')
    return 0;
  if (strcmp(A, "a") < 0.)
    return 0;
  if (!strcmp(A, "a"))
    return 0;
}
void test_structure_patterns() {
  if (strcmp(A, "a")) {}
  while (strcmp(A, "a")) {}
  for (;strcmp(A, "a");) {}
}
int test_valid_patterns() {
  if (strcmp(A, "a") < 0) return 0;
  if (strcmp(A, "a") == 0) return 0;
  if (strcmp(A, "a") <= 0) return 0;
  if (strcmp(A, "a") == strcmp(A, "b")) return 0;
  return 1;
}
int wrapper(const char* a, const char* b) {
  return strcmp(a, b);
}
int assignment_wrapper(const char* a, const char* b) {
  int cmp = strcmp(a, b);
  return cmp;
}
int condexpr_wrapper(const char* a, const char* b) {
  return (a < b) ? strcmp(a, b) : strcmp(b, a);
}
