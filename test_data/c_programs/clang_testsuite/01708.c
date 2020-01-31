typedef const char rchar;
int a(char* a, rchar* b) {
  return a-b;
}
void f0(void (*fp)(void)) {
  int x = fp - fp;
}
