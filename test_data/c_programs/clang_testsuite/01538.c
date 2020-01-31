static void* malloc(int);
static void* malloc(int size) {
  return ((void*)0);
}
void *calloc(int, int, int);
void f1(void) {
  calloc(0, 0, 0);
}
void f2() {
  int index = 1;
}
static int index;
int f3() {
  return index << 2;
}
typedef int rindex;
