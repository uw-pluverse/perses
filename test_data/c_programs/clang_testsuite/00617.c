void bar(int);
void foo(int x, int y, int z) {
  int m;
  for (m = 0; m < x ; m++) {
    int a = (((y >> 8) & 0xff) * z) / 256;
    bar(a < 255 ? a : 255);
  }
}
