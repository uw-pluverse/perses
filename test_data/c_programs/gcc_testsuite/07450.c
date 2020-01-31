



signed short in[512 +1024];
signed short coeff[1024];
signed short out[512];



void
foo (){
  int i,j;
  int diff;

  for (i = 0; i < 512; i++) {
    diff = 0;
    for (j = 0; j < 1024; j+=8) {
      diff += in[j+i]*coeff[j];
    }
    out[i]=diff;
  }
}
