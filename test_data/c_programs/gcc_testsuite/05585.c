


float e(float *x, float *y, float *z)
{
  float m = __builtin_sqrt (*x * *x + *y * *y + *z * *z);
  *x /= m;
  *y /= m;
  *z /= m;
}
