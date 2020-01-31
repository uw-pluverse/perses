



unsigned char in[96 +128];
unsigned short out[96];



void
foo (){
  int i,j;
  unsigned short diff;

  for (i = 0; i < 96; i++) {
    diff = 0;
    for (j = 0; j < 128; j+=8) {
      diff += in[j+i];
    }
    out[i]=diff;
  }
}
