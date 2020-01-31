




typedef unsigned char e_u8;
e_u8 x[256];



static inline void bar1(e_u8 a[4][8], e_u8 b[4][8], int n)
{
  int i, j;

  for(i = 0; i < 4; i++)
    for(j = 0; j < n; j++)
      a[i][j] ^= b[i][j];
}

static inline void bar2(e_u8 a[4][8], e_u8 b[256], int n)
{
  int i, j;

  for(i = 0; i < 4; i++)
    for(j = 0; j < n; j++)
      a[i][j] = b[a[i][j]] ;
}

int foo1 (e_u8 a[4][8], int b1, int b2, e_u8 b[14 +1][4][8])
{
  int n;
  int r, m;

  switch (b2) {
    case 128: n = 4; break;
    case 192: n = 6; break;
    case 256: n = 8; break;
    default : return (-2);
  }
  switch (((b1)>=(b2)?(b1):(b2))) {
    case 128: m = 10; break;
    case 192: m = 12; break;
    case 256: m = 14; break;
    default : return (-3);
  }
  bar1(a,b[m],n);
  bar2(a,x,n);
  return 0;
}
