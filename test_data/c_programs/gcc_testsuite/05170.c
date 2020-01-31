


float
quantum_real(float _Complex a)
{
  float *p = (float *) &a;
  return p[0];
}
float
quantum_imag(float _Complex a)
{
  float *p = (float *) &a;
  return p[1];
}
float
quantum_foo(float _Complex a)
{
  float *p = (float *) &a;
  return p[2];
}
