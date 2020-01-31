


int vnum_test8(int *data)
{
  int i;
  int stop = data[3];
  int m = data[4];
  int n = m;
  int p = 0;

  for (i=0; i<stop; i++) {
    int k = data[2];
    data[5] = 0;
    if (i < 30)
      data[5] = m - n;
    p = data[5];
    k = data[1];
    m = m + k;
    n = n + k;
  }
  return p;
}
