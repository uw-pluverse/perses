static union ibtt2
{
  struct ibtt0 { signed ibt0:10; unsigned short ibt1; } ibt5;
  struct ibtt1 { signed ibt2:3; signed ibt3:9; signed ibt4:9; } ibt6;
} ibt15 = {{267, 15266}};
void callee_ibt0f(union ibtt2 ibtp5);
void test(void) {
  callee_ibt0f(ibt15);
}
