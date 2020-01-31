typedef float v4sf __attribute__((vector_size(16)));
typedef int v4si __attribute__((vector_size(16)));

v4sf ivf, ovf;
v4si ivi, ovi;

void testf (void)
{
  ovf = ivf - ivf;
}

void testi (void)
{
  ovi = ivi - ivi;
}
