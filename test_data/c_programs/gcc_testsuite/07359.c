





void fbar (float *);
void ibar (int *);
void sbar (short *);



void
foo (int n)
{
  float a[16 +1];
  float b[16];
  float c[16];
  float d[16];
  int ia[16];
  int ib[16];
  int ic[16];
  int i,j;
  int diff = 0;
  char cb[16];
  char cc[16];
  char image[16][16];
  char block[16][16];


  diff = 0;
  for (i = 0; i < 16; i++) {
    diff += (cb[i] - cc[i]);
  }
  ibar (&diff);



  diff = 0;
  for (i = 0; i < 16; i++) {
    for (j = 0; j < 16; j++) {
      diff += (image[i][j] - block[i][j]);
    }
  }
  ibar (&diff);



  for (i = 0; i < 16; i++){
    a[i] = b[i];
  }
  fbar (a);



  for (i = 0; i < 16; i++){
    a[i] = b[i] + c[i] + d[i];
  }
  fbar (a);




  for (i = 0; i < 16/2; i++){
    a[i] = b[2*i+1] * c[2*i+1] - b[2*i] * c[2*i];
    d[i] = b[2*i] * c[2*i+1] + b[2*i+1] * c[2*i];
  }
  fbar (a);



  for (i = 0; i < 16; i++){
    a[i] = b[i] + c[i];
    d[i] = b[i] + c[i];
    ia[i] = ib[i] + ic[i];
  }
  ibar (ia);
  fbar (a);
  fbar (d);


  for (i = 0; i < 16; i++){
    a[i] = b[i] + c[i];
    a[i+1] = b[i] + c[i];
  }
  fbar (a);
}
