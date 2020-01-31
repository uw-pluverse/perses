


typedef int intflt;





union U {
  intflt i;
  float f;
};
intflt foo(int i, int b)
{
  union U u;
  if (b)
    {
      i = i << 2;
      u.i = i;
      return u.f;
    }
  else
    {
      i = i << 2;
      u.i = i;
      return u.f;
    }
}
