


volatile int *a, *b, N;
typedef int tint;
struct someclass {
  int a;
  char b;
  int *p;
};

void foo()
{
 for (int i=0; i < N; ++i)
    a[i] = b[i];

 for (int i=0; i < N; ++i)
    a[i] = b[i];
}
