




extern void abort (void);
extern int strcmp (const char *, const char *);
extern void exit (int);

int
main (void)
{
  if (strcmp (__func__, "main") || sizeof (__func__) != 5)
    abort ();
  else
    exit (0);
}
