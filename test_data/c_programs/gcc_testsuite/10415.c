

typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;
inline __attribute__ ((always_inline)) void
e(int t, ...)
{
  va_list q;
  __builtin_va_start(q, t);
}
