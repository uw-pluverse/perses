int floatcomptest(double *X, double *Y, float *x, float *y) {
  return *X < *Y || *x < *y;
}
extern void *malloc(unsigned);
void *memset_impl(void *dstpp, int c, unsigned len) {
  long long int dstp = (long long int) dstpp;
  while (dstp % 4 != 0)
    {
      ((unsigned char *) dstp)[0] = c;
      dstp += 1;
      len -= 1;
    }
  return dstpp;
}
static char *temp;
static int remaining;
static char *localmalloc(int size) {
  char *blah;
  if (size>remaining)
    {
      temp = (char *) malloc(32768);
      remaining = 32768;
      return temp;
    }
  return 0;
}
typedef struct { double X; double Y; int Z; } PBVTest;
PBVTest testRetStruct(float X, double Y, int Z) {
  PBVTest T = { X, Y, Z };
  return T;
}
PBVTest testRetStruct2(void);
double CallRetStruct(float X, double Y, int Z) {
  PBVTest T = testRetStruct2();
  return T.X+X+Y+Z;
}
