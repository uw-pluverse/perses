unsigned int in1 [1024] __attribute__((__aligned__(32)));
unsigned int in2 [1024] __attribute__((__aligned__(32)));
unsigned int eqv [1024] __attribute__((__aligned__(32)));
unsigned int nand1[1024] __attribute__((__aligned__(32)));
unsigned int nand2[1024] __attribute__((__aligned__(32)));
unsigned int orc1 [1024] __attribute__((__aligned__(32)));
unsigned int orc2 [1024] __attribute__((__aligned__(32)));

void
do_eqv (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    {
      eqv[i] = ~(in1[i] ^ in2[i]);
    }
}

void
do_nand1 (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    {
      nand1[i] = ~(in1[i] & in2[i]);
    }
}

void
do_nand2 (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    {
      nand2[i] = (~in1[i]) | (~in2[i]);
    }
}

void
do_orc1 (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    {
      orc1[i] = (~in1[i]) | in2[i];
    }
}

void
do_orc2 (void)
{
  unsigned long i;

  for (i = 0; i < 1024; i++)
    {
      orc1[i] = in1[i] | (~in2[i]);
    }
}
