


int f(float *);
int g(float x)
{
  return f(&(float){x}) + f(&x);
}
