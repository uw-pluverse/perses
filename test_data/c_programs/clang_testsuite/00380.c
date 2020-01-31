__thread int a;
extern __thread int b;
int c() { return *&b; }
int d() {
  __thread static int e;
  __thread static union {float a; int b;} f = {.b = 1};
  return 0;
}
__thread int g __attribute__((tls_model("global-dynamic")));
__thread int h __attribute__((tls_model("local-dynamic")));
__thread int i __attribute__((tls_model("initial-exec")));
__thread int j __attribute__((tls_model("local-exec")));
int f() {
  __thread static int a __attribute__((tls_model("initial-exec")));
  return a++;
}
