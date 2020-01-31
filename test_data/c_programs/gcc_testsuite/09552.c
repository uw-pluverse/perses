





extern void abort (void);
extern void exit (int);


typedef unsigned int uint32_t;
uint32_t
f (uint32_t a, uint32_t b)
{

  b = (((a) << ((int)(b & 31))) | ((a) >> (32 - (int)(b & 31))));
  return b;
}

int
main ()
{
  if (f(2,31) != 1)
    abort ();
  exit (0);
}
