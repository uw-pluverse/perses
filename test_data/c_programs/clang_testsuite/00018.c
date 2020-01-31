int *returnNull() { return 0; }
int coin();
void testCycle(float i) {
  int *x = returnNull();
  int y;
  while (i > 0) {
    x = returnNull();
    y = 2;
    i -= 1;
  }
  *x = 1;
  y += 1;
}
