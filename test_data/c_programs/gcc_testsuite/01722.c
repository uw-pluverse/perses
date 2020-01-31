


extern void abort (void);
extern void exit (int);

unsigned long foo (unsigned long base, unsigned int val)
{
  return base + (val & 0x80000001);
}

int main (void)
{
  if (foo (0L, 0x0ffffff0) != 0L)
    abort ();
  exit (0);
}
