





extern void exit (int);
extern void abort (void);

static int i;

int
main (void)
{
  i = -1;
  switch ((signed char) i) {
  case 255:
    abort ();
  default:
    exit (0);
  }
}
