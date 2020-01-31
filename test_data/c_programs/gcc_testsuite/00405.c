signed char ca[16] __attribute__((aligned(16)));
signed char cb[] __attribute__((aligned(16)))
  = {8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7};
signed char cc[] __attribute__((aligned(16)))
  = {1, 1, 2, 2, 3, 3, 2, 2, 1, 1, 0, 0, -1, -1, -2, -2};

__attribute__((noinline)) void foo ()
{
  int i;
  for (i = 0; i < 16; i++) {
    ca[i] = cb[i] - cc[i];
  }
}
