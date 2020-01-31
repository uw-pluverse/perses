





typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

typedef int int32x2_t __attribute__ ((__vector_size__ ((8))));

int test (int i, ...);

int
main (int argc, char **argv)
{
  int32x2_t a = (int32x2_t) {0, 1};
  int32x2_t b = (int32x2_t) {2, 3};
  return test (2, a, b);
}
