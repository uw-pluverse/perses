struct a {
  signed b;
  long c;
  unsigned d;
} static e(struct a f) {
  f.b;
  for (;;)
    ;
}
void g() {
  struct a h;
  e(h);
  for (;;) {
    struct a i;
    h = i = h;
  }
}
int main() {}
