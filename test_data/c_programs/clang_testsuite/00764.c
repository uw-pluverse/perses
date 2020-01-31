typedef struct {
  float f[3];
} S0;
extern void foo2(S0);
void foo1(S0 a0) {
  foo2(a0);
}
