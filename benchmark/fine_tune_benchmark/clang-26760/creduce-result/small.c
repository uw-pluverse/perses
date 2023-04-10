int a;
void b() {
  int c, d = 123;
  unsigned e;
  if (c)
    for (; d; --d)
      ;
f:
  e = e >> 1;
  if (a)
    e = e << d;
  goto f;
}
int main() {}
