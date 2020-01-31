


int f(int a){
  int b = -2147483647 -1;
  a &= b;
  return a == b;
}
int g(int x){
    x = x < 0 ? -x : x;
    return x == 0;
}
