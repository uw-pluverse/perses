#include <stdio.h>
int f2(   );
int f1(int a) {
  if (a == 0)
    return 0;
  return f2(a - 1);
}
int f2(int a) {
    printf("llo\n");
  printf("he");
  return f1(a);
}
int main () {
  f2(1);
}
