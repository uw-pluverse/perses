


extern int flag;

int foo() {

  int x;
  int y = 9;
  float* q;
  float* r;

  if (flag) {
    q = (float*) &x;
  } else {
    q = (float*) &y;
  }

  *q = 1.0;

  return x;

}
