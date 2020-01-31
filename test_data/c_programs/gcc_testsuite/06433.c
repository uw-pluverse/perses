

int f(int a, int b){
  a %= b;
  return a % b;
}
int g(unsigned a, unsigned b){
  a %= b;
  return a < b;
}
