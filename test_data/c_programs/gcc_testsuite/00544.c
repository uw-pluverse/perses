






void abort ();


int ca[4096] __attribute__((aligned(16)));
int cb[4096] __attribute__((aligned(16)));
int cc[4096] __attribute__((aligned(16)));
int cd[4096] __attribute__((aligned(16)));

__attribute__((noinline)) void foo ()
{
  int i;
  for (i = 0; i < 4096; i++) {
    ca[i] = ((cb[i] + cc[i]) * cd[i]) >> 3;
  }
}

__attribute__((noinline)) void init ()
{
  int i;
  for (i = 0; i < 4096; ++i) {
    cb[i] = 3 * i - 2048;
    cc[i] = -5 * i + 93;
    cd[i] = i % 2 ? 1 : -1;
  }
}

int main ()
{
  int i;
  init ();
  foo ();
  for (i = 0; i < 4096; ++i)
    if (i % 2 == 1 && ca[i] != (-2 * i - 1955) >> 3)
      abort ();
    else if (i % 2 == 0 && ca[i] != (1955 + 2 * i) >> 3)
      abort ();
  return 0;
}
