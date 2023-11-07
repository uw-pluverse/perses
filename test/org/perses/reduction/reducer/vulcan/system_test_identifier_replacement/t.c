#include <stdio.h>

void f(int i){
   printf("%d\n", i);
}
int main() {
   int a = 123;
   int b = 123;
   f(b);
   return a;
}
