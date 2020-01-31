int begin(int i) {
  if (i)
    return 0;
  return 1;
}
int end(int i) {
  if (i)
    return 0;
  return 1;
}
int main(int argc, const char *argv[]) {
  begin(0);
  end(1);
  if (argc)
    return 0;
  return 1;
}
