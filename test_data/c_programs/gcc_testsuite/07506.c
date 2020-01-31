



unsigned int in[40 +128];
unsigned short out[40];



void
foo (){
  int i,j;
  unsigned int diff;

  for (i = 0; i < 40; i++) {
    diff = 0;
    for (j = 0; j < 128; j+=8) {
      diff += in[j+i];
    }
    out[i]=(unsigned short)diff;
  }

  return;
}
