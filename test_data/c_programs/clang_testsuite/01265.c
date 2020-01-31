int __llvm_profile_runtime = 0;
int __llvm_profile_register_write_file_atexit(void);
void __llvm_profile_set_filename(const char *);
int main(int argc, const char *argv[]) {
  __llvm_profile_register_write_file_atexit();
  if (argc < 2)
    return 1;
  __llvm_profile_set_filename(argv[1]);
  return 0;
}
