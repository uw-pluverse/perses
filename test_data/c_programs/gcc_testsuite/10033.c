



struct U
{
  float f;
  int i;
};


int foo ()
{
  struct U u;
  float *pf = (float*)&u;
  *pf = 2.0;
  return u.i;
}
