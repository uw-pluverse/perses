





void __attribute__ ((target("fpu=neon")))
 f1(int n, int x[], int y[]) {
  int i;
  for (i = 0; i < n; ++i)
    y[i] = x[i] << 3;
}

void __attribute__ ((target("fpu=vfp")))
f3(int n, int x[], int y[]) {
  int i;
  for (i = 0; i < n; ++i)
    y[i] = x[i] << 3;
}
