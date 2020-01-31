

typedef struct { char c[8]; } V

  __attribute__ ((aligned (8)))

  ;
typedef long unsigned int size_t;
V v;
void abort (void);

int
main (void)
{
  V *w = &v;
  if (((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8) != 0
      || ((size_t) w & 1))
    {



 abort ();
    }
  return 0;
}
