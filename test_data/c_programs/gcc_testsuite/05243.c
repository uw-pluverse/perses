






extern long unsigned int strlen (const char *);
extern void bar (long unsigned int);
extern int bla (void);

void foo(int i)
{
  char *s = "abcde";

  if (i)
    {
      s = "defgh";
      goto middle;
    }

start:

  bla ();

middle:

  if (bla ())
    goto start;

  bar (strlen (s));
}
