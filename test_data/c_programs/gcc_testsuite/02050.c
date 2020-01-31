
extern void exit (int);
extern void abort (void);

volatile unsigned int i;

int
main (void)
{
  unsigned char z = 0;

  do ++i;
  while (--z > 0);
  if (i != (127*2 +1) + 1U)
    abort ();
  exit (0);
}
