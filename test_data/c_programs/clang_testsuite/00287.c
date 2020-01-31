int strcmp(const char *s1, const char *s2);
int test(char *X) {
  return strcmp(X, "\037\213");
}
