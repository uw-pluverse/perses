

static double P[10000][10000];

void sor(int N1, int N2){
  int i, j, k;

 for(i=1; i<N1-1; i++) {
    for(j=1; j<N2-1; j++) {
      P[i][j] = (P[i][j] + P[i][j-1] + P[i][j+1] + P[i-1][j] + P[i+1][j]) / 5;
    }
  }
}
