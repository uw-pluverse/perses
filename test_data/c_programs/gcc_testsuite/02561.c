



extern void abort (void);
extern void exit (int);

volatile unsigned u = 0x80000081;



volatile float f1, f2;
int
main (void)
{
  f1 = (float) u;
  f2 = (float) 0x80000081;
  if (f1 != f2)
    abort ();
  exit (0);
}
