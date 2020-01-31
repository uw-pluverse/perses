void foo(void);
void foo() { return; }
int main() {
  int i;
  for (i = 0; i < 10000; i++) foo();
  return 0;
}
