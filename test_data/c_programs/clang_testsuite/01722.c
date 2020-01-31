void func() {
  return;
  int i = 0;
}
void func2() {
  for(int i = 0; i < 10; ++i) {
    if(i > 2) {
      return;
    }
    if(i == 3) {
      int j = 1;
    } else {
      int j = 2;
    }
  }
}
void func3(int x) {
  if(x > 5) {
    while(x >= 9) {
      return;
      --x;
    }
    int i = 0;
  }
  int j = 0;
}
int main(int argc, const char *argv[]) {
  func();
  func2();
  func3(10);
}
