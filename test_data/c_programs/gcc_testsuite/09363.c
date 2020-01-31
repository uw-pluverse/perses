


unsigned f(unsigned x, unsigned y){
  return (x | y) & ~x;
}
unsigned g(unsigned x, unsigned y){
  return ~x & (y | x);
}
