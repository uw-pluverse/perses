__attribute__((weak)) void does_not_exist(void);
__attribute__((noinline))
void foo(void (*p)(void)) {
  p();
}
int main(int argc, char **argv) {
  if (does_not_exist)
    foo(does_not_exist);
}
