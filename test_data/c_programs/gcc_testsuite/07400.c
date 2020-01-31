





void fbar (float *);
void ibar (int *);
void sbar (short *);



void
foo (int n)
{
  float a[128 +1];
  float b[128];
  float c[128];
  float d[128];
  int ia[128];
  int ib[128];
  int ic[128];
  int i,j;
  int diff = 0;
  char cb[128];
  char cc[128];
  char image[128][128];
  char block[128][128];


  diff = 0;
  for (i = 0; i < 128; i++) {
    diff += (cb[i] - cc[i]);
  }
  ibar (&diff);



  diff = 0;
  for (i = 0; i < 128; i++) {
    for (j = 0; j < 128; j++) {
      diff += (image[i][j] - block[i][j]);
    }
  }
  ibar (&diff);



  for (i = 0; i < 128; i++){
    a[i] = b[i];
  }
  fbar (a);



  for (i = 0; i < 128; i++){
    a[i] = b[i] + c[i] + d[i];
  }
  fbar (a);




  for (i = 0; i < 128/2; i++){
    a[i] = b[2*i+1] * c[2*i+1] - b[2*i] * c[2*i];
    d[i] = b[2*i] * c[2*i+1] + b[2*i+1] * c[2*i];
  }
  fbar (a);



  for (i = 0; i < 128; i++){
    a[i] = b[i] + c[i];
    d[i] = b[i] + c[i];
    ia[i] = ib[i] + ic[i];
  }
  ibar (ia);
  fbar (a);
  fbar (d);


  for (i = 0; i < 128; i++){
    a[i] = b[i] + c[i];
    a[i+1] = b[i] + c[i];
  }
  fbar (a);
}
