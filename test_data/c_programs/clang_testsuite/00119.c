void debug_captured() {
  int x = 10;
#pragma clang __debug captured
  {
    if (x) {}
  }
  if (x) {}
#pragma clang __debug captured
  {
    for (int i = 0; i < x; ++i) {}
    if (x) {}
  }
  if (x) {}
}
int main(int argc, const char *argv[]) {
  debug_captured();
  return 0;
}
