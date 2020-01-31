


int f1(int a, int b){
  int c = a & b;
  return c & b;
}
int f2(int a, int b){
  int c = a | b;
  return b | c;
}
int g1(int a, int b, int c){
  int d = a & b;
  int e = b & c;
  return d & e;
}
int g2(int a, int b, int c){
  int d = a | b;
  int e = c | b;
  return d | e;
}
int g3(int a, int b, int c){
  int d = a ^ b;
  int e = b ^ c;
  return e ^ d;
}
