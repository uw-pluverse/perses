int __llvm_profile_dump(void);
void __llvm_profile_reset_counters(void);
int foo(int);
int bar(int);
int skip(int);
int main(int argc, const char *argv[]) {
  int Ret = foo(0);
  __llvm_profile_dump();
  skip(0);
  __llvm_profile_reset_counters();
  Ret += bar(0);
  __llvm_profile_dump();
  skip(1);
  __llvm_profile_reset_counters();
  foo(1);
  __llvm_profile_dump();
  return Ret;
}
__attribute__((noinline)) int foo(int X) {
  return X <= 0 ? -X : X;
}
__attribute__((noinline)) int skip(int X) {
  return X <= 0 ? -X : X;
}
__attribute__((noinline)) int bar(int X) {
  return X <= 0 ? -X : X;
}
