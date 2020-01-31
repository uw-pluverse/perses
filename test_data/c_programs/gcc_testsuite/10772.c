

extern void exit (int);
extern void *foo (void);

void *p;

int
main ()
{
  p = foo ();
  exit (0);
}
