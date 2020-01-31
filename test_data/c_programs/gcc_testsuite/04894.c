



float a[1024], b[1024];

float
foo ()
{
  float s = 0.f;
  unsigned int i;
 for (i = 0; i < 1024; ++i)
    s += a[i] * b[i];
  return s;
}
