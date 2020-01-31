


int vnum_test8(int *data)
{
  int i;
  int stop = data[3];
  int m = data[4];
  int n = m;
  int p;
  for (i=0; i<stop; i++) {
    int k = data[2];
    data[k] = 2;
    data[0] = m - n;
    k = data[1];
    m = m + k;
    n = n + k;
    p = data[0];
  }
  return p;
}
