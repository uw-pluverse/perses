

typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

typedef int int32x2_t __attribute__ ((__vector_size__ ((8))));

int
test (int i, ...)
{
  va_list argp;
  __builtin_va_start(argp, i);
  int32x2_t x = (int32x2_t) {0, 1};
  x += __builtin_va_arg(argp, int32x2_t);
  return x[0] + x[1];
}
