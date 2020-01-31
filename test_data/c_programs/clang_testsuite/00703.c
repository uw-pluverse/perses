char s[];
static void bar(void *db) {
  eek(s);
}
char s[5] = "hi";
int foo() {
  bar(0);
}
