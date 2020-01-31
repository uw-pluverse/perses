


signed short image[160][160];
signed short block[160][160];
signed short out[160];



void
foo (){
  int i,j;
  int diff;

  for (i = 0; i < 160; i++) {
    diff = 0;
    for (j = 0; j < 160; j+=4) {
      diff += (image[i][j] - block[i][j]);
    }
    out[i]=diff;
  }
}
