extern double sqrt (double);
extern double fabs (double);
extern double ceil (double);
extern double floor (double);

extern void abort (void);




typedef struct {
    int initialHeight, initialWidth;
    int rotatedHeight, rotatedWidth;
    int autoCropHeight, autoCropWidth;
} ufraw_data;

void __attribute__((noinline,noclone))
ufraw_test(ufraw_data *uf)
{
  int iWidth = uf->initialWidth;
  int iHeight = uf->initialHeight;
  double aspectRatio = ((double)iWidth) / iHeight;
  double midX = iWidth / 2.0 - 0.5;
  double midY = iHeight / 2.0 - 0.5;
  double maxX = 0, maxY = 0;
  double minX = 999999, minY = 999999;
  double lastX = 0, lastY = 0, area = 0;
  double scale;
  int i;
  for (i = 0; i < iWidth + iHeight - 1; i++)
    {
      int x, y;
      if (i < iWidth) {
   x = i;
   y = 0;
      } else {
   x = iWidth - 1;
   y = i - iWidth + 1;
      }
      double srcX = x - midX;
      double srcY = y - midY;

      area += srcY * lastX - srcX * lastY;
      lastX = srcX;
      lastY = srcY;
      maxX = (((maxX) > (fabs(srcX))) ? (maxX) : (fabs(srcX)));
      maxY = (((maxY) > (fabs(srcY))) ? (maxY) : (fabs(srcY)));
      if (fabs(srcX / srcY) > aspectRatio)
 minX = (((minX) < (fabs(srcX))) ? (minX) : (fabs(srcX)));
      else
 minY = (((minY) < (fabs(srcY))) ? (minY) : (fabs(srcY)));
    }
  scale = sqrt((iWidth - 1) * (iHeight - 1) / area);
  uf->rotatedWidth = (((ceil(2 * maxX + 1.0) * scale) < (2 * iWidth)) ? (ceil(2 * maxX + 1.0) * scale) : (2 * iWidth));
  uf->rotatedHeight = (((ceil(2 * maxY + 1.0) * scale) < (2 * iHeight)) ? (ceil(2 * maxY + 1.0) * scale) : (2 * iHeight));
  uf->autoCropWidth = (((floor(2 * minX) * scale) < (2 * iWidth)) ? (floor(2 * minX) * scale) : (2 * iWidth));
  uf->autoCropHeight = (((floor(2 * minY) * scale) < (2 * iHeight)) ? (floor(2 * minY) * scale) : (2 * iHeight));
  if (uf->autoCropWidth != 3)
    abort ();
}

int main()
{
  ufraw_data uf_data;
  ufraw_data *uf = &uf_data;
  uf->initialWidth = 4;
  uf->initialHeight = 5;
  ufraw_test(uf);
  return 0;
}
