void no_usable_data() {
  int i = 0;
  if (i) {}
}
void no_data() {
}
int main(int argc, const char *argv[]) {
  no_usable_data();
  return 0;
}
