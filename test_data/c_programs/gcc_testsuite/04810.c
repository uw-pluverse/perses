


volatile int ten = 10;

int main() {
  volatile char x[10];
  x[ten] = 1;
  return 0;
}
