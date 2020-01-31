void func(int x) {
  if (x) {}
  do { if (0) {} } while (0);
  do { if (!x) {} } while (0);
  do { if (x) {} } while (0);
  do { do { if (x) {} } while (0); } while (0);
  if (((x) && (x))) {}
  if (((x) || (x))) {}
  if (((x) + (x))) {}
  if ((x)) {}
}
int main(int argc, const char *argv[]) {
  func(0);
}
