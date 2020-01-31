int main() {
  char *s;
  s = (char []){"whatever"};
  s = (char(*)){s};
}
