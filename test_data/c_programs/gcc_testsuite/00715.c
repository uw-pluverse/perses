



extern void abort (void);

typedef struct bitfield
{
  unsigned short eight: 8;
  unsigned short four: 4;
  unsigned short five: 5;
  unsigned short seven: 7;
  unsigned int sixteen: 16;
} bitfield;

bitfield
bfi1 (bitfield a)
{

  a.eight = 3;
  return a;
}

bitfield
bfi2 (bitfield a)
{

  a.five = 7;
  return a;
}

bitfield
movk (bitfield a)
{

  a.sixteen = 7531;
  return a;
}

bitfield
set1 (bitfield a)
{

  a.five = 0x1f;
  return a;
}

bitfield
set0 (bitfield a)
{

  a.five = 0;
  return a;
}


int
main (int argc, char** argv)
{
  static bitfield a;
  bitfield b = bfi1 (a);
  bitfield c = bfi2 (b);
  bitfield d = movk (c);

  if (d.eight != 3)
    abort ();

  if (d.five != 7)
    abort ();

  if (d.sixteen != 7531)
    abort ();

  d = set1 (d);
  if (d.five != 0x1f)
    abort ();

  d = set0 (d);
  if (d.five != 0)
    abort ();

  return 0;
}
