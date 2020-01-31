struct AB{const char *a; const char*b;};
const char *foo(const struct AB *ab) {
  return ab->a + 'b';
}
void f(const char *s) {
  char *str = 0;
  char *str2 = str + 'c';
  const char *constStr = s + 'c';
  str = 'c' + str;
  char strArr[] = "foo";
  str = strArr + 'c';
  char *strArr2[] = {"ac","dc"};
  str = strArr2[0] + 'c';
  struct AB ab;
  constStr = foo(&ab) + 'c';
  char c = 'c';
  str = str + c;
  str = c + str;
}
