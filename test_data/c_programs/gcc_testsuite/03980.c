void
foo (unsigned int n, int x, int y, unsigned char *z)
{
  int a, b;
  float c[2048][4];

  switch (x)
    {
    case 0x1906:
      a = b = -1;
      break;
    case 0x190A:
      a = b = -1;
      break;
    case 0x8049:
      a = b = -1;
      break;
    case 0x1907:
      a = 1;
      b = 2;
      break;
    default:
      return;
    }

  if (a >= 0)
    {
      unsigned char *d = z;
      unsigned int i;
      for (i = 0; i < n; i++)
 {
   do
     {
       union
       {
  float r;
  unsigned int i;
       }
       e;
       e.r = c[i][1];
       d[a] =
  ((e.i >= 0x3f7f0000) ? ((int) e.i <
         0) ? (unsigned char) 0
   : (unsigned char) 255 : (e.r =
       e.r * (255.0F / 256.0F) +
       32768.0F, (unsigned char) e.i));
     }
   while (0);
   d += y;
 }
    }

  if (b >= 0)
    {
      unsigned char *d = z;
      unsigned int i;
      for (i = 0; i < n; i++)
 {
   do
     {
       union
       {
  float r;
  unsigned int i;
       }
       e;
       e.r = c[i][2];
       d[b] =
  ((e.i >= 0x3f7f0000) ? ((int) e.i <
         0) ? (unsigned char) 0
   : (unsigned char) 255 : (e.r =
       e.r * (255.0F / 256.0F) +
       32768.0F, (unsigned char) e.i));
     }
   while (0);
   d += y;
 }
    }
}
