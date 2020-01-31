



extern



void *memset (void *, int, long unsigned int);

volatile int ten = 10;

int main() {
  char x[10];
  memset(x, 0, 10);
  int res = x[ten];
  return res;
}
