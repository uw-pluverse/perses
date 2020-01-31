int z1 = 0;
int z2;
int __thread x;
int f() {
  static int __thread y;
  return y++;
}
int __thread __attribute__((tls_model("initial-exec"))) z;
