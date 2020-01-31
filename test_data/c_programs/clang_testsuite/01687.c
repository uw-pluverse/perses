typedef int Arr[10];
typedef int trungl_int;
void f(int a[10], Arr arr) {
  (void)sizeof(a);
  (void)sizeof((((a))));
  (void)sizeof a;
  (void)sizeof arr;
  int b[10];
  (void)sizeof b;
  Arr brr;
  (void)sizeof brr;
  (void)sizeof(Arr);
  (void)sizeof(int);
}
