int main() {
  int j = 0;
  for(int i = 0; i < 20; ++i) {
    if(i < 10) {
      if(i < 5) {
        continue;
        j = 1;
      } else {
        j = 2;
      }
      j = 3;
      if(i < 7) {
        continue;
        j = 4;
      } else j = 5;
      j = 6;
    } else
      j = 7;
    j = 8;
  }
}
