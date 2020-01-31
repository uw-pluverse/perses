volatile char x[4000] __attribute__((aligned(0x100000)));
int
main (int argc, char ** argv) {
  volatile char y[4000] __attribute__((aligned(0x100000)));
  return y[argc];
}
