typedef const struct __CFString * CFStringRef;
void f() {
  (CFStringRef) __builtin___CFStringMakeConstantString ("Hello, World!");
}
void *G = (CFStringRef) __builtin___CFStringMakeConstantString ("yo joe");
