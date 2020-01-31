void __llvm_profile_set_filename(const char *);
int main(int argc, const char *argv[]) {
  if (argc < 2)
    return 1;
  __llvm_profile_set_filename(argv[1]);
  __llvm_profile_set_filename(0);
  return 0;
}
