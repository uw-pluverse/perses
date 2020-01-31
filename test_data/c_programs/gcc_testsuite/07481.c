


signed short image[256][256] __attribute__ ((__aligned__(16)));
signed short block[256][256] __attribute__ ((__aligned__(16)));



int
foo (){
  int i,j;
  int diff = 0;

  for (i = 0; i < 256; i++) {
    for (j = 0; j < 256; j+=8) {
      diff += (image[i][j] - block[i][j]);
    }
  }
  return diff;
}
