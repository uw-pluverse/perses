#include <stdio.h>

int f1() {
  return 0;
}

int g1 = 0 + 1 + 2 + 3 + 4 + 6 + 8 + 9 + 10;

int f2() {
  return g1 + 1;
}

int f3() {
  return f2() + g1;
}

int f4() {
  return f1() + g1;
}

int main () {
  printf("hello %d\n", g1);
  return f4() + g1;
}
