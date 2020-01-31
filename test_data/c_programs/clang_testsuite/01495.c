static int a16[];
void f16(void) {
    extern int a16[];
}
extern int PR10013_x;
int PR10013(void) {
  int *PR10013_x = 0;
  {
    extern int PR10013_x;
    extern int PR10013_x;
  }
  return PR10013_x;
}
static int test1_a[];
extern int test1_a[];
void test2declarer() { extern int test2_array[100]; }
extern int test2_array[];
int test2v = sizeof(test2_array);
void test3declarer() {
  { extern int test3_array[100]; }
  extern int test3_array[];
  int x = sizeof(test3_array);
}
void test4() {
  extern int test4_array[];
  {
    extern int test4_array[100];
    int x = sizeof(test4_array);
  }
  int x = sizeof(test4_array);
}
extern void abort(void);
extern float *calloc();
void test5a() {
  int abort();
  float *malloc();
  int *calloc();
}
void test5b() {
  int abort();
  float *malloc();
  int *calloc();
}
void test5c() {
  void (*_abort)(void) = &abort;
  void *(*_malloc)() = &malloc;
  float *(*_calloc)() = &calloc;
}
void test6() {
  extern int test6_array1[100];
  extern int test6_array2[100];
  void test6_fn1(int*);
  void test6_fn2(int*);
  {
    char test6_array2;
    char test6_fn2;
    {
      extern int test6_array1[];
      extern int test6_array2[];
      (void)sizeof(test6_array1);
      (void)sizeof(test6_array2);
      void test6_fn1();
      void test6_fn2();
      test6_fn1(1.2);
      test6_fn2(1.2);
    }
  }
}
