



signed short in[40 +128];
signed short coeff[128];
int out[40];



void
foo (){
  int i,j;
  int diff;

  for (i = 0; i < 40; i++) {
    diff = 0;
    for (j = 0; j < 128; j+=8) {
      diff += in[j+i]*coeff[j];
    }
    out[i]=diff;
  }
}
