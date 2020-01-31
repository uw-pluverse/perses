



extern void abort (void);



void foo (void)
{
  int dst[256], src[256];
  unsigned int i;

  __builtin_memset (src, 0, 256 * sizeof (int));
  __builtin_memcpy (dst, src, 256 * sizeof (int));
  if (__builtin_memcmp (dst, src, 256 * sizeof (int)) != 0)
    abort ();
}
