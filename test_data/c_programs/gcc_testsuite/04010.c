

int r, t;

static void initRGB()
{
  t = ((r*255/3) & 0xff) << 16;
}
