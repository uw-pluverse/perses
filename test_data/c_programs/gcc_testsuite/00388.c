




extern int a[];
int foo(int w) {
  int n = w;
  while (n >= 512)
    {
    a[n] = 42;
    n -= 256;
    }
  }
