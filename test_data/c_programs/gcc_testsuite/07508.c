


signed short image[40][40];
signed short block[40][40];



__attribute__ ((noinline)) unsigned int
foo (){
  int i,j;
  unsigned int diff = 0;

  for (i = 0; i < 40; i++) {
    for (j = 0; j < 40; j++) {
      diff += (image[i][j] - block[i][j]);
    }
  }
  return diff;
}
