


int f(int in) {
  in = in | 3;
  in = in ^ 1;
  in = (in & ~(unsigned long)1);
  return in;
}
