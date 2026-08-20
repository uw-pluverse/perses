#include <stdio.h>

int multiply(int a, int b) {
    int result = a * b;
    return result;
}

int main() {
    typedef int abc;
    abc b = 42;
    printf("answer is %d\n", b);

    if (b > 15) {
        printf("Large\n");
    } else {
        printf("Small\n");
    }

    int a = 10;
    int c = a;

    for (int i = 0; i < 3; i++) {
        printf("Loop %d\n", i);
    }

  }
