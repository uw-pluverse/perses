


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern int __vprintf_chk (int, const char *, va_list);
volatile int vi0, vi1, vi2, vi3, vi4, vi5, vi6, vi7, vi8, vi9, via;

void
test (va_list ap1, va_list ap2, va_list ap3, va_list ap4, va_list ap5,
      va_list ap6, va_list ap7)
{
  vi0 = 0;
  __vprintf_chk (1, "hello", ap1);
  vi1 = 0;
  __vprintf_chk (1, "hello\n", ap2);
  vi2 = 0;
  __vprintf_chk (1, "a", ap3);
  vi3 = 0;
  __vprintf_chk (1, "", ap4);
  vi4 = 0;
  __vprintf_chk (1, "%s", ap5);
  vi5 = 0;
  __vprintf_chk (1, "%c", ap6);
  vi6 = 0;
  __vprintf_chk (1, "%s\n", ap7);
  vi7 = 0;
}
