


int f(double aaa, double bbb){
  int xa = !__builtin_isunordered(aaa, aaa);
  int xb = !__builtin_isunordered(bbb, bbb);
  return xa & xb;
}

int g(double aaa, double bbb){
  int xa = !__builtin_isunordered(aaa, bbb);
  int xb = !__builtin_isunordered(bbb, bbb);
  return xa & xb;
}

int h(double ccc, float ddd){
  int xc = !__builtin_isunordered(ccc, ccc);
  int xd = !__builtin_isunordered(ddd, ddd);
  return xc & xd;
}
