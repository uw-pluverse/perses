


extern float sqrtf (float);

float t1(float a, float b)
{
  return a/sqrtf(b);
}

float t2(float a, float b)
{
  return sqrtf(a/b);
}

float t3(float a)
{
  return sqrtf(a);
}
