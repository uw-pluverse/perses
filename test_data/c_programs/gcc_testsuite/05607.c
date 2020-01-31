


unsigned f(unsigned i){
  i >>= 4 * 8 - 3;
  i = ~i;
  return i & 7;
}
