


typedef unsigned char uchar;
typedef struct rgb_ {uchar r; uchar g; uchar b;} rgb;

rgb in[512], out[512];
float c[512];
void foo(int n)
{
  int i, j;
  for (i = 0; i < n; i++)
    {
      float r = 0, g = 0, b = 0;
      for (j = 0; j < 5; j++)
 {
   r += (float)in[i + j].r * c[j];
   g += (float)in[i + j].g * c[j];
   b += (float)in[i + j].b * c[j];
 }
      out[i].r = (uchar)r;
      out[i].g = (uchar)g;
      out[i].b = (uchar)b;
    }
}
