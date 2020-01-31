void f() {
  __builtin___CFStringMakeConstantString("Hello, World!");
}
void *G = __builtin___CFStringMakeConstantString("yo joe");
void h() {
  static void* h = __builtin___CFStringMakeConstantString("Goodbye, World!");
}
