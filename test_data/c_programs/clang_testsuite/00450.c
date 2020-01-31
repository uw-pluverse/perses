int gi;
typedef unsigned long size_t;
void *my_malloc(size_t) __attribute__((alloc_size(1)));
void *my_calloc(size_t, size_t) __attribute__((alloc_size(1, 2)));
void test1() {
  void *const vp = my_malloc(100);
  gi = __builtin_object_size(vp, 0);
  gi = __builtin_object_size(vp, 1);
  gi = __builtin_object_size(vp, 2);
  gi = __builtin_object_size(vp, 3);
  void *const arr = my_calloc(100, 5);
  gi = __builtin_object_size(arr, 0);
  gi = __builtin_object_size(arr, 1);
  gi = __builtin_object_size(arr, 2);
  gi = __builtin_object_size(arr, 3);
  gi = __builtin_object_size(my_malloc(100), 0);
  gi = __builtin_object_size(my_malloc(100), 1);
  gi = __builtin_object_size(my_malloc(100), 2);
  gi = __builtin_object_size(my_malloc(100), 3);
  gi = __builtin_object_size(my_calloc(100, 5), 0);
  gi = __builtin_object_size(my_calloc(100, 5), 1);
  gi = __builtin_object_size(my_calloc(100, 5), 2);
  gi = __builtin_object_size(my_calloc(100, 5), 3);
  void *const zeroPtr = my_malloc(0);
  gi = __builtin_object_size(zeroPtr, 0);
  gi = __builtin_object_size(my_malloc(0), 0);
  void *const zeroArr1 = my_calloc(0, 1);
  void *const zeroArr2 = my_calloc(1, 0);
  gi = __builtin_object_size(zeroArr1, 0);
  gi = __builtin_object_size(zeroArr2, 0);
  gi = __builtin_object_size(my_calloc(1, 0), 0);
  gi = __builtin_object_size(my_calloc(0, 1), 0);
}
void test2() {
  void *const vp = my_malloc(gi);
  gi = __builtin_object_size(vp, 0);
  void *const arr1 = my_calloc(gi, 1);
  gi = __builtin_object_size(arr1, 0);
  void *const arr2 = my_calloc(1, gi);
  gi = __builtin_object_size(arr2, 0);
}
void test3() {
  char *const buf = (char *)my_calloc(100, 5);
  gi = __builtin_object_size(buf, 0);
  gi = __builtin_object_size(buf, 1);
  gi = __builtin_object_size(buf, 2);
  gi = __builtin_object_size(buf, 3);
}
struct Data {
  int a;
  int t[10];
  char pad[3];
  char end[1];
};
void test5() {
  struct Data *const data = my_malloc(sizeof(*data));
  gi = __builtin_object_size(data, 0);
  gi = __builtin_object_size(data, 1);
  gi = __builtin_object_size(data, 2);
  gi = __builtin_object_size(data, 3);
  gi = __builtin_object_size(&data->t[1], 0);
  gi = __builtin_object_size(&data->t[1], 1);
  gi = __builtin_object_size(&data->t[1], 2);
  gi = __builtin_object_size(&data->t[1], 3);
  struct Data *const arr = my_calloc(sizeof(*data), 2);
  gi = __builtin_object_size(arr, 0);
  gi = __builtin_object_size(arr, 1);
  gi = __builtin_object_size(arr, 2);
  gi = __builtin_object_size(arr, 3);
  gi = __builtin_object_size(&arr->t[1], 0);
  gi = __builtin_object_size(&arr->t[1], 1);
  gi = __builtin_object_size(&arr->t[1], 2);
  gi = __builtin_object_size(&arr->t[1], 3);
}
void test6() {
  struct Data *const data = my_malloc(sizeof(*data) + 10);
  gi = __builtin_object_size(data->end, 0);
  gi = __builtin_object_size(data->end, 1);
  gi = __builtin_object_size(data->end, 2);
  gi = __builtin_object_size(data->end, 3);
  struct Data *const arr = my_calloc(sizeof(*arr) + 5, 3);
  gi = __builtin_object_size(arr->end, 0);
  gi = __builtin_object_size(arr->end, 1);
  gi = __builtin_object_size(arr->end, 2);
  gi = __builtin_object_size(arr->end, 3);
  gi = __builtin_object_size(arr[0].end, 0);
  gi = __builtin_object_size(arr[0].end, 1);
  gi = __builtin_object_size(arr[0].end, 2);
  gi = __builtin_object_size(arr[0].end, 3);
  gi = __builtin_object_size(arr[1].end, 0);
  gi = __builtin_object_size(arr[1].end, 1);
  gi = __builtin_object_size(arr[1].end, 2);
  gi = __builtin_object_size(arr[1].end, 3);
  gi = __builtin_object_size(arr[2].end, 0);
  gi = __builtin_object_size(arr[2].end, 1);
  gi = __builtin_object_size(arr[2].end, 2);
  gi = __builtin_object_size(arr[2].end, 3);
}
void test7() {
  struct Data *const data = my_malloc(sizeof(*data) + 5);
  gi = __builtin_object_size(data->pad, 0);
  gi = __builtin_object_size(data->pad, 1);
  gi = __builtin_object_size(data->pad, 2);
  gi = __builtin_object_size(data->pad, 3);
}
void test8() {
  void *buf = my_calloc(100, 5);
  gi = __builtin_object_size(buf, 0);
  gi = __builtin_object_size(buf, 1);
  gi = __builtin_object_size(buf, 2);
  gi = __builtin_object_size(buf, 3);
}
void test9() {
  short *const buf0 = (my_malloc(100));
  short *const buf1 = (short*)(my_malloc(100));
  short *const buf2 = ((short*)(my_malloc(100)));
  gi = __builtin_object_size(buf0, 0);
  gi = __builtin_object_size(buf1, 0);
  gi = __builtin_object_size(buf2, 0);
}
void test10() {
  short *const arr = my_calloc((size_t)-1 / 2 + 1, 2);
  gi = __builtin_object_size(arr, 0);
  gi = __builtin_object_size(arr, 1);
  gi = __builtin_object_size(arr, 2);
  gi = __builtin_object_size(arr, 3);
  short *const buf = my_malloc((size_t)-1);
  gi = __builtin_object_size(buf, 0);
  gi = __builtin_object_size(buf, 1);
  gi = __builtin_object_size(buf, 2);
  gi = __builtin_object_size(buf, 3);
  short *const arr_big = my_calloc((size_t)-1 / 2 - 1, 2);
  gi = __builtin_object_size(arr_big, 0);
  gi = __builtin_object_size(arr_big, 1);
  gi = __builtin_object_size(arr_big, 2);
  gi = __builtin_object_size(arr_big, 3);
}
void *my_tiny_malloc(char) __attribute__((alloc_size(1)));
void *my_tiny_calloc(char, char) __attribute__((alloc_size(1, 2)));
void test11() {
  void *const vp = my_tiny_malloc(100);
  gi = __builtin_object_size(vp, 0);
  gi = __builtin_object_size(vp, 1);
  gi = __builtin_object_size(vp, 2);
  gi = __builtin_object_size(vp, 3);
  void *const arr = my_tiny_calloc(100, 5);
  gi = __builtin_object_size(arr, 0);
  gi = __builtin_object_size(arr, 1);
  gi = __builtin_object_size(arr, 2);
  gi = __builtin_object_size(arr, 3);
}
void *my_signed_malloc(long) __attribute__((alloc_size(1)));
void *my_signed_calloc(long, long) __attribute__((alloc_size(1, 2)));
void test12() {
  gi = __builtin_object_size(my_signed_malloc(100), 0);
  gi = __builtin_object_size(my_signed_calloc(100, 5), 0);
  void *const vp = my_signed_malloc(-2);
  gi = __builtin_object_size(vp, 0);
  gi = __builtin_object_size(my_signed_malloc(-2), 0);
  void *const arr1 = my_signed_calloc(-2, 1);
  void *const arr2 = my_signed_calloc(1, -2);
  gi = __builtin_object_size(arr1, 0);
  gi = __builtin_object_size(arr2, 0);
  gi = __builtin_object_size(my_signed_calloc(1, -2), 0);
  gi = __builtin_object_size(my_signed_calloc(-2, 1), 0);
}
