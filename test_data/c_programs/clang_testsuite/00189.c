void f1(void) {
  int x = 0;
#pragma STDC FP_CONTRACT ON
}
void f2(void) {
#pragma STDC FP_CONTRACT OFF
#pragma STDC FP_CONTRACT ON
}
