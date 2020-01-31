


float u, v, w, x, y, z;

void e(float a, float b, float c, float d, float e, float f)
{
  if (a < b)
    {
      a = a + b;
      c = c + d;
    }


  d = d / a;
  e = e / a;
  f = f / a;

  a = a / c;
  b = b / c;


  c = 1 / c;

  u = a;
  v = b;
  w = c;
  x = d;
  y = e;
  z = f;
}
