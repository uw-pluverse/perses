void testIndexOverflow64() {
  char arr[0x100000000];
  char *ptr = arr + (~0u)/2;
  ptr += 2;
  *ptr = 42;
}
void testIndexTooBig64() {
  char arr[(~0ul)/8-1];
  char *ptr = arr + ((~0ul)/16);
  ptr += 2;
  *ptr = 42;
}
