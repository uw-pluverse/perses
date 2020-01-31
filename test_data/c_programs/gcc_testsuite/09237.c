






extern void abort (void);

int main (void)
{

  short xLoc;
  short xIn, xOut, xExpect, i = 1;

  xLoc = xIn = ~ (1 << i);
  xExpect = ~ (xIn & 0x7F);

  xOut = __sync_nand_and_fetch (&xLoc, 0x7F);

  if (xOut != xExpect)
    abort ();

  return 0;
}
