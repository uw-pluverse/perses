



void abort ();


signed char ca[256] __attribute__((aligned(16)));
signed char cb[256] __attribute__((aligned(16)));
signed char cc[256] __attribute__((aligned(16)));

__attribute__((noinline)) void foo ()
{
  int i;
  for (i = 0; i < 256; i++) {
    ca[i] = cb[i] - cc[i];
  }
}

__attribute__((noinline)) void init ()
{
  int i;
  for (i = 0; i < 256; ++i) {
    cb[i] = i - 128;
    cc[i] = i/2 - 64;
  }
}

int main ()
{
  int i;
  init ();
  foo ();
  for (i = 0; i < 256; ++i)
    if (ca[i] != i - i/2 - 64)
      abort ();
  return 0;
}
