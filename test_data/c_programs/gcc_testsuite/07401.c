


signed short image[256][256] __attribute__ ((__aligned__(16)));
signed short block[256][256] __attribute__ ((__aligned__(16)));
signed short out[256] __attribute__ ((__aligned__(16)));



void
foo (){
  int i,j;
  int diff;

  for (i = 0; i < 256; i++) {
    diff = 0;
    for (j = 0; j < 256; j+=8) {
      diff += (image[i][j] - block[i][j]);
    }
    out[i]=diff;
  }
}
