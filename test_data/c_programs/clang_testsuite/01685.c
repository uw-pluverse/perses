const char *filename (const char *name) {
  static const char this_file[] = "/tmp/llvm-builder/llvm-source-trunk/tools/clang/test/CoverageMapping/builtinmacro.c";
  return this_file;
}
int main() {
  filename("/tmp/llvm-builder/llvm-source-trunk/tools/clang/test/CoverageMapping/builtinmacro.c" "test.c");
  return 0;
}
