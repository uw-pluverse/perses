


float *x;
float parm;
float
test (int start, int end)
{
  int i;
  for (i = start; i < end; ++i)
    {
      float tem = x[i];
      x[i] = parm * tem;
    }
}
