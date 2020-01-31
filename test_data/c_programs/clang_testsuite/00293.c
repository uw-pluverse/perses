void calla();
void callb();
void callc();
void test1(int a) {
  if (a)
    calla();
  else
    callb();
  callc();
}
void test2(int a) {
  if (!a)
    callb();
  else
    calla();
  callc();
}
