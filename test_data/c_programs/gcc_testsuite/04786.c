



extern



void *memset (void *, int, long unsigned int);

volatile int ten = 10;

int main() {
  static char XXX[10];
  static char YYY[10];
  static char ZZZ[10];
  memset(XXX, 0, 10);
  memset(YYY, 0, 10);
  memset(ZZZ, 0, 10);
  int res = YYY[ten];
  res += XXX[ten/10] + ZZZ[ten/10];
  return res;
}
