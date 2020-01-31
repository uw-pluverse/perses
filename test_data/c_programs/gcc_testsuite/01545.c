


extern float sinf (float);
extern float cosf (float);

float
sincos_add (float x)
{
  float s = sinf (x);
  float c = cosf (x);

  return s + c;
}
