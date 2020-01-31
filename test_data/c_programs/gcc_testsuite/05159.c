




void blas (signed char xxx);
void blau (unsigned char xxx);

void tst(void)
{
  unsigned i;

  for (i = 0; i < 129; i++)
    blas ((signed char) i);
  for (i = 0; i < 128; i++)
    blas ((signed char) i);
  for (i = 0; i < 127; i++)
    blas ((signed char) i);
  for (i = 0; i < 256; i++)
    blau ((unsigned char) i);
  for (i = 0; i < 257; i++)
    blau ((unsigned char) i);
}
