#include <stdio.h>
int f1(int);
int f2(int);

void irrelevant_func() {
}

int f1(int a) {
  irrelevant_func();
  if (a == 0) {
    return 0;
  }
  return f2(a - 1);
}

int f2(int a) {
  irrelevant_func();
  if (a == 0) {
    printf("llo\n");
    return f1(a);
  }
  printf("he");
  return f1(a);
}

int main () {
  irrelevant_func();
  f2(1);
  return 0;
}
