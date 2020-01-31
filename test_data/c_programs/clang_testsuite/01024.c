extern int g0_ext __attribute__((weak));
extern int __attribute__((weak)) g1_ext (void);
int g0_common __attribute__((weak));
int g0_def __attribute__((weak)) = 52;
int __attribute__((weak)) g1_def (void) { return 0; }
void f0() {
  int a = g0_ext;
  int b = g1_ext();
}
