


volatile int ten = 10;

int main() {
  volatile static char XXX[10];
  XXX[ten];
  return 0;
}
