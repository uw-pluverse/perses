int main() {
  int cnt = 0;
  while(cnt < 100) {
    break;
    ++cnt;
  }
  while(cnt < 100) {
    {
      break;
      ++cnt;
    }
    ++cnt;
  }
  while(cnt < 100) {
    if(cnt == 0) {
      break;
      ++cnt;
    }
    ++cnt;
  }
  while(cnt < 100) {
    if(cnt == 0) {
      ++cnt;
    } else {
      break;
    }
    ++cnt;
  }
}
