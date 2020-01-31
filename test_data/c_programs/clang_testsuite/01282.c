int __llvm_profile_runtime = 0;
void __llvm_profile_initialize_file(void);
int __llvm_profile_write_file(void);
void __llvm_profile_set_filename(const char *);
int foo(int);
int main(int argc, const char *argv[]) {
  if (argc > 42)
    return 1;
  __llvm_profile_initialize_file();
  __llvm_profile_write_file();
  return foo(0);
}
int foo(int X) {
  return X <= 0 ? -X : X;
}
