


int f (int a0,int a1,int a2,int a3,int a4)
{
int b0, b1, b2, b3, b4,e;

  b4 = a4 + a3 + a2 + a1 + a0;
  b3 = a3 + a2 + a1 + a0;
  b2 = a2 + a1 + a0;
  b1 = a1 + a0;

  e = b4 - b3 + b2 - b1 - a4 - a2;
  return e;
}
