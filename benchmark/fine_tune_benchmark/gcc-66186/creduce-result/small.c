int a;
short b;
void c(unsigned short);
void e() {
  int d = -7L;
  c(d);
}
void c(unsigned short f) {
  int g;
  short h[8];
  for (; b <= 7; b++) {
    g = 0;
    for (; g <= 7; g++)
      if (a < 0) {
        g = 0;
        for (; g <= 7; g++)
          if (h[f])
            break;
      }
  }
}
int main() { e(); }
