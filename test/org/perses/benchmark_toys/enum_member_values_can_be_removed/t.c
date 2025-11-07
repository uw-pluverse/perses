#include <stdio.h>

enum Level {
  ZERO = 0,
  LOW = 1,
  MEDIUM = 20,
  HIGH = 30
};

int main () {
  int result;
  if (LOW < MEDIUM) {
    printf("hello\n");
    result = LOW;
  } else {
    result = 20;
  }
  return result;
}