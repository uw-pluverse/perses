

static double a[3000][3000], b[3000][3000], c[3000][3000];

void dsyr2k(long N) {
 int i,j,k;

 for (i=0; i<N; i++) {
  for (j=0; j<N; j++) {
   for (k=j; k<N; k++) {
    c[j][k] += a[i][j] * b[i][k] + b[i][j] * a[i][k];
   }
  }
 }
}
