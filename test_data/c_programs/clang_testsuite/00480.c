typedef int __attribute__((vector_size (8))) i32v2;
int a(i32v2 x) { return x[0]; }
typedef int __attribute__((vector_size (16))) i32v4;
int b(i32v4 x) { return x[0]; }
