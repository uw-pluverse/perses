





int abs_called = 0;

extern int abs (int);
extern long labs (long);
extern void abort (void);

void
main_test (void)
{
  if (labs (0) != 0)
    abort ();
  if (abs (0) != 0)
    abort ();
  if (!abs_called)
    abort ();
}
