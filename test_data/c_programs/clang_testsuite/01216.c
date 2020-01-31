void abort() {}
void f(void) {
  int x = 1;
  if (!(x == 0)) abort();
  if (!(11 == 5 + 6)) abort();
  if (!(10 == 5 + 5)) abort();
}
