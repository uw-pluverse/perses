


signed short image[64][64] __attribute__ ((__aligned__(16)));
signed short block[64][64] __attribute__ ((__aligned__(16)));
signed short out[64] __attribute__ ((__aligned__(16)));



void
foo (){
  int i,j;
  int diff;

  for (i = 0; i < 64; i++) {
    diff = 0;
    for (j = 0; j < 64; j+=8) {
      diff += (image[i][j] - block[i][j]);
    }
    out[i]=diff;
  }
}
