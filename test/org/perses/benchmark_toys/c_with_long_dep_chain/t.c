#include <stdio.h>

int f1() {

  return 0;
}

int f2() {

  return f1() + 1;
}

int f3() {

  return f2();
}

int f4() {

  return f1();
}

int main (int argc, char *argv[]) {
  int a;
  a = 0;
  int b;
  int e;
  b = a + 1;
  int c;
  int d;
  c = b + 2;
  int f;
  d = c + 3;
  e = d + 4;
  f = e + 5;
  printf("hello\n");
  return f4();
}
