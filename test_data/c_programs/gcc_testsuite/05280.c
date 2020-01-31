


extern int __printf_chk (int, const char *, ...);
volatile int vi0, vi1, vi2, vi3, vi4, vi5, vi6, vi7, vi8, vi9, via;

void test (void)
{
  vi0 = 0;
  __printf_chk (1, "hello");
  vi1 = 0;
  __printf_chk (1, "hello\n");
  vi2 = 0;
  __printf_chk (1, "a");
  vi3 = 0;
  __printf_chk (1, "");
  vi4 = 0;
  __printf_chk (1, "%s", "hello");
  vi5 = 0;
  __printf_chk (1, "%s", "hello\n");
  vi6 = 0;
  __printf_chk (1, "%s", "a");
  vi7 = 0;
  __printf_chk (1, "%s", "");
  vi8 = 0;
  __printf_chk (1, "%c", 'x');
  vi9 = 0;
  __printf_chk (1, "%s\n", "hello\n");
  via = 0;
}
