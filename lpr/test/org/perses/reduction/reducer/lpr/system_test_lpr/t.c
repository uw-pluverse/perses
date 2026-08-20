#include <stdio.h>
typedef int length;
length b[100];
int init() {
  return 100;
}
int main() {
  length a = init();
  for (int i = 0; i < 10; i++) {
    b[i] = a - i;
  }
  printf("%d", b[6]);
  return 0;
}
