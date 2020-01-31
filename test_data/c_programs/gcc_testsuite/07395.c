



typedef struct
{
  short real;
  short imag;
} complex16_t;

void
libvector_AccSquareNorm_ref (unsigned int *acc,
        const complex16_t *x, unsigned len)
{
  unsigned i;
  for (i = 0; i < len; i++)
    acc[i] += ((unsigned int)((int)x[i].real * x[i].real))
 + ((unsigned int)((int)x[i].imag * x[i].imag));
}
