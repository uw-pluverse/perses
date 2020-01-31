typedef struct BF {
  int A : 1;
  char B;
  int C : 13;
} BF;
char *test1(BF *b) {
  return &b->B;
}
void test2(BF *b) {
  b->A++;
  --b->C;
}
void test3(BF *b) {
   b->C = 12345;
}
int test4(BF *b) {
  return b->C;
}
void test5(BF *b, int i) {
  b[i].C = 12345;
}
