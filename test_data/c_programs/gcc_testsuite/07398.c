






void foo(int n, int *a, int *b, int *c) {
  int i;
 i = 0;
 while(i < n)
    {
      a[i] = b[i] + c[i];
      ++i;
    }
}

void bar(int n, int *a, int *b, int *c) {
  int i;
 i = 0;
 do
    {
      a[i] = b[i] + c[i];
      ++i;
    }
  while(i < n);
}
