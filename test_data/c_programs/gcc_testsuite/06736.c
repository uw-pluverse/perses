




__fp16 h0 = -1.0;
__fp16 h1 = 0.0;
__fp16 h2 = 1234.0;
__fp16 h3 = 42.0;
float f1 = 2.0;
float f2 = -999.9;

void f (__fp16 *p)
{
  __fp16 t;

  h0 = 1.0;
  h1 = h2;
  h2 = f1;
  f2 = h2;

  t = *p;
  *p = h3;
  h3 = t;
}
