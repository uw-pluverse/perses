



extern void abort (void);

void foo (char *c)
{
  int i;
  unsigned x = 0;
  {
    for (i = 0; i < 64; i += 4)
 x = x | *((unsigned *) (&c[i]));
    if (x)
      abort ();
  }
}
