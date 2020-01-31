


int winner, numf2s;
double **tds;
double d, tsum;

typedef struct {
  double y;
} xyz;

xyz *Y;
int ti;

double
match (void)
{
  int tj, tresult;

  for (tj = 0; tj < numf2s; tj++)
    if (tj == winner
 && Y[tj].y > 0)
      tsum += tds[ti][tj] * d;

  return tsum;
}
