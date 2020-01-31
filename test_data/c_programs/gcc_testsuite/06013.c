


extern int printf (const char *, ...);
volatile int vi0, vi1, vi2, vi3, vi4, vi5, vi6, vi7, vi8, vi9, via;

void test (void)
{
  vi0 = 0;
  printf ("hello");
  vi1 = 0;
  printf ("hello\n");
  vi2 = 0;
  printf ("a");
  vi3 = 0;
  printf ("");
  vi4 = 0;
  printf ("%s", "hello");
  vi5 = 0;
  printf ("%s", "hello\n");
  vi6 = 0;
  printf ("%s", "a");
  vi7 = 0;
  printf ("%s", "");
  vi8 = 0;
  printf ("%c", 'x');
  vi9 = 0;
  printf ("%s\n", "hello\n");
  via = 0;
}
