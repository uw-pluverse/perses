struct foo {
  int a;
};
int main() {
  struct foo xxx;
  int i;
  xxx = (struct foo)1;
  i = (int)xxx;
}
