


unsigned f(unsigned i){
  i >>= 4 * 8 - 1;
  return i == 0;
}
