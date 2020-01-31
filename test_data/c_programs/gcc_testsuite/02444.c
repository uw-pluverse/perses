





extern void abort (void);
extern long unsigned int strlen (const char *);
extern char *strcpy (char *, const char *);
static const char bar[] = "Hello, World!";
static const char baz[] = "hello, world?";
static const char larger[20] = "short string";
extern int inside_main;

int l1 = 1;
int x = 6;

void
main_test(void)
{





  if (strlen (bar) != 13)
    abort ();

  if (strlen (bar + 3) != 10)
    abort ();

  if (strlen (&bar[6]) != 7)
    abort ();

  if (strlen (bar + (x++ & 7)) != 7)
    abort ();
  if (x != 7)
    abort ();
  if (strlen (larger) != 12)
    abort ();
  if (strlen (&larger[10]) != 2)
    abort ();

  inside_main = 0;


  if (strlen (larger + (x++ & 7)) != 5)
    abort ();
  if (x != 8)
    abort ();
  inside_main = 1;
}
