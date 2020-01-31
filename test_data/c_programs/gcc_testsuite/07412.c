



signed short in[320 +1024];
signed short coeff[1024];
int out[320];



void
foo (){
  int i,j;
  int diff;

  for (i = 0; i < 320; i++) {
    diff = 0;
    for (j = 0; j < 1024; j+=8) {
      diff += in[j+i]*coeff[j];
    }
    out[i]=diff;
  }
}
