typedef long int intptr_t;
int foo();
int global;
void test1() {
  int i = 0;
#pragma clang __debug captured
  {
    static float inner = 3.0;
    (void)inner;
    i++;
  }
}
void test2(int x) {
#pragma clang __debug captured
  {
    int i;
    for (i = 0; i < x; i++)
      foo();
  }
}
void test3(int size) {
  int arr[] = {1, 2, 3, 4, 5};
  int vla_arr[size];
#pragma clang __debug captured
  {
    arr[2] = vla_arr[size - 1];
  }
}
void test4(intptr_t size, intptr_t vla_arr[size]) {
#pragma clang __debug captured
  {
    vla_arr[0] = 1;
  }
}
void dont_capture_global() {
  static int s;
  extern int e;
#pragma clang __debug captured
  {
    global++;
    s++;
    e++;
  }
}
