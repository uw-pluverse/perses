int a, b;
volatile int c;
unsigned d;
void e() {
  for (; b; b++) {
    a = 0;
    for (; a >= -27; a = a - 6)
      d = 5 - d;
  }
  d || c;
}
int main() {}
