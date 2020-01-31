


float foo(float x, float y, float z)
{
  float a = __builtin_fmaf (x, y, z);
  float b = __builtin_fmaf (x, y, z);
  return a - b;
}
