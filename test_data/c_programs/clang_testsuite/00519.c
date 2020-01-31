void bork() {
  char * volatile p = 0;
  volatile int cc = 0;
  p += cc;
}
