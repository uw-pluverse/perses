


typedef struct { int i; } FILE;
FILE *fp;
extern int fprintf (FILE *, const char *, ...);
volatile int vi0, vi1, vi2, vi3, vi4, vi5, vi6, vi7, vi8, vi9;

void test (void)
{
  vi0 = 0;
  fprintf (fp, "hello");
  vi1 = 0;
  fprintf (fp, "hello\n");
  vi2 = 0;
  fprintf (fp, "a");
  vi3 = 0;
  fprintf (fp, "");
  vi4 = 0;
  fprintf (fp, "%s", "hello");
  vi5 = 0;
  fprintf (fp, "%s", "hello\n");
  vi6 = 0;
  fprintf (fp, "%s", "a");
  vi7 = 0;
  fprintf (fp, "%c", 'x');
  vi8 = 0;
  fprintf (fp, "%d%d", vi0, vi1);
  vi9 = 0;
}
