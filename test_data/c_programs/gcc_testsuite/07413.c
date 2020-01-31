

typedef unsigned char uint8_t;
int
vsad16_c (void *c, uint8_t * s1, uint8_t * s2, int stride, int h)
{
  int score = 0;
  int x, y;
  for (x = 0; x < 16; x++)
    score += ((s1[x] - s1[x + stride] + s2[x + stride]) >= 0 ?
              s1[x] + s2[x + stride] :
              s2[x + stride]);
  return score;
}
