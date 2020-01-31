typedef int plain_i;
typedef int *ip;
typedef const int *cip;
typedef void (*func_ptr)(void);
void func(void) {
  const int *i0 = 0;
  const plain_i *i1 = 0;
  const cip i2 = 0;
  const ip i3 = 0;
  ip const i4 = 0;
  const volatile ip i5 = 0;
}
void func2(const plain_i *i1,
           const cip i2,
           const ip i3,
           const int *i4) {
}
struct S {
  const int *i0;
  const plain_i *i1;
  const cip i2;
  const ip i3;
};
void func3(const func_ptr fp) {
  const func_ptr fp2 = fp;
}
