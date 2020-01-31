


signed short image[40][40];
signed short block[40][40];
signed short out[40];



void
foo (){
  int i,j;
  int diff;

  for (i = 0; i < 40; i++) {
    diff = 0;
    for (j = 0; j < 40; j+=4) {
      diff += (image[i][j] - block[i][j]);
    }
    out[i]=diff;
  }
}
