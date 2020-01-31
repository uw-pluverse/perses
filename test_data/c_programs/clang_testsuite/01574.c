void abcdefghi12(void) {
 const char (*ss)[12] = &__func__;
 static int arr[sizeof(__func__)==12 ? 1 : -1];
}
char *X = __func__;
void a() {
  __func__[0] = 'a';
}
const char *b = __func__;
const char *c = __FUNCTION__;
const char *d = __PRETTY_FUNCTION__;
