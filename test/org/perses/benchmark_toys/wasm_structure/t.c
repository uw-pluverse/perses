#include <stdio.h>

int main() {
  int a = 1;
  if (a%2 == 1) {
    printf("hello world\n");
  } else {
    printf("unreachable\n");
  }
  return 0;
}