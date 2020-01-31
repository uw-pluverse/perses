int __llvm_profile_write_file(void);
void __llvm_profile_set_filename(const char *);
int foo(int);
int main(int argc, const char *argv[]) {
  if (argc < 2)
    return 1;
  __llvm_profile_write_file();
  int Ret = foo(0);
  __llvm_profile_set_filename(argv[1]);
  return Ret;
}
int foo(int X) {
  return X <= 0 ? -X : X;
}
